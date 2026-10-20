#include <windows.h>

#include <QApplication>
#include <QQuickStyle>
#include <QSortFilterProxyModel>
#include <QThread>

#include "data-processing/cache-manager.h"
#include "models/entry-commisions-list-model.h"
#include "models/stats-page-model.h"
#include "models/tables-list-model.h"
#include "models/tree-view-model.h"
#include "qml-modules/window-manager.h"
#include "utils/app-paths-manager.h"
#include "utils/database-manager.h"
#include "utils/qml-helper.h"
#include "utils/logger.h"
#include "utils/progress-handler.h"
#include "utils/theme-manager.h"

/// Метод нужен просто для компактности кода
/// @param QmlHelper& qmlHelper
/// @param CacheManager& cacheManager
/// @param TreeViewModel& treeViewModel
/// @param StatsPageModel& statsPageModel
/// @return void
void connectSignals(QmlHelper& qmlHelper, CacheManager& cacheManager, TreeViewModel& treeViewModel,
		    StatsPageModel& statsPageModel) {

    // Сигнал поступает из qml с информацией нахождении файла таблицы которую надо обработать в CacheManager
    // где будет дальше решено что делать с таблицей
    QObject::connect(&qmlHelper, &QmlHelper::sendSignalToProceedTable, &cacheManager,
                     &CacheManager::processTable);

    // После успешной обработки таблицы отправляется сигнал sendProceededData с результатом обработки.
    // Результат устанавливается в модель древесного представления
    QObject::connect(&cacheManager, &CacheManager::sendProceededData, &treeViewModel,
                     &TreeViewModel::setFaculties);

    // После успешной обработки таблицы отправляется сигнал sendProceededData с результатом обработки.
    // Результат устанавливается в модель страниц статистики
    QObject::connect(&cacheManager, &CacheManager::sendProceededData, &statsPageModel,
		     &StatsPageModel::setFaculties);


}

/// Метод нужен для первичной инициализации CacheManager в другом потоке
/// @param QThread& thread объект потока в который передаём CacheManager
/// @param CacheManager& cacheManager сам CacheManager
/// @return void
void moveToThread(QThread& thread, CacheManager& cacheManager) {

    cacheManager.moveToThread(&thread);

    // Инициализация объекта в потоке после старта самого потока
    QObject::connect(&thread, &QThread::started, &cacheManager, &CacheManager::init);

    thread.start();
}

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    //----Система логирования----------------------------------------
    Logger::initLog();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    qInstallMessageHandler(Logger::logHandler);

    //----Системные утилиты------------------------------------------
    AppPathsManager::init();            // менеджер путей
    DataBaseManager::instance().init(); // менеджер БД

    //----Потоки ----------------------------------------------------
    QThread cacheThread;

    //----Компоненты логики и представления--------------------------
    QmlHelper                qmlHelper;       // коллекция методов для qml (не объеденнёных в одну логическую группу)
    CacheManager             cacheManager;    // менеджер кэша и обработки таблиц
    TablesListModel          tablesListModel; // модель списка таблиц для qml
    QSortFilterProxyModel    proxyModel;      // таже модель что и выше, но с возможностью сортировки содержимого
    TreeViewModel            treeViewModel;   // модель древесного представления иерархии факультетов и направлений для qml
    StatsPageModel           statsPageModel;  // модель страниц статистики
    EntryCommisionsListModel entryModel;      // модель списка доступных правил приёма (приёмных коммисий)
    ProgressHandler          progressHandler; // контролер состояния прогресс бара
    ThemeManager             themeManager;    // мэнэджер визуальной темы

    qmlHelper.setAppVersion("26.01");

    connectSignals(qmlHelper, cacheManager, treeViewModel, statsPageModel);
    moveToThread(cacheThread, cacheManager);

    proxyModel.setSourceModel(&tablesListModel);
    proxyModel.setSortRole(TablesListModel::TablesListRoles::tableNameRole);

    //----Объекты ответственные за весь визуал программы-------------
    QQmlApplicationEngine engine;
    WindowManager::init(&engine);
    QQuickStyle::setStyle("Basic");

    //----передача объектов для qml в его контекст (можно воспринимать как глобальную область видимости)
    engine.rootContext()->setContextProperty("sortFilterProxyModel", &proxyModel);
    engine.rootContext()->setContextProperty("tablesListModel", &tablesListModel);
    engine.rootContext()->setContextProperty("qmlHelper", &qmlHelper);
    engine.rootContext()->setContextProperty("progressHandler", &progressHandler);
    engine.rootContext()->setContextProperty("windowManager", &WindowManager::instance());
    engine.rootContext()->setContextProperty("treeViewModel", &treeViewModel);
    engine.rootContext()->setContextProperty("statsPageModel", &statsPageModel);
    engine.rootContext()->setContextProperty("entryCommisionsListModel", &entryModel);
    engine.rootContext()->setContextProperty("applicantsListModel", statsPageModel.getApplicantsListModel().get());
    engine.rootContext()->setContextProperty("Colors", &themeManager);
    engine.loadFromModule("ApplicantStatsProjectModule", "Main");

    int ret = QApplication::exec();

    cacheThread.quit();
    cacheThread.wait();

    return ret;
}
