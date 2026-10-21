#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <QDir>
#include <QFileSystemWatcher>
#include <QHash>
#include <QString>
#include <memory>

#include "../app-utils/app-paths-manager.h"
#include "../applicants-faculty-priority/faculty-direction.h"
#include "../tables-processing/table-parser-bachelor.h"
#include "magic-hat.h"

class CacheManager : public QObject {
    Q_OBJECT
public:
    void init();

    static QString tableNameInCache(const QString& tableName, const QVariantList& infoList);
    static QString tableLastChangeDate(const QString& tableName);

signals:
    void processTable(const QString& tableName, const QVariantList& infoList);
    void sendProceededData(std::shared_ptr<QList<FacultyDirection>> data);
    void waitForFinish();
    void finished();

private:
    void processTableHandle(const QString& tableName, const QVariantList& infoList);
    std::shared_ptr<QList<FacultyDirection>> loadCache(const QString& tableName, const QVariantList& infoList);
    std::shared_ptr<QList<FacultyDirection>> makeCache(const QString& tableName, const QVariantList& infoList);
    static void saveCache(const std::shared_ptr<QList<FacultyDirection>>& data,
                          const QString& tableName, const QVariantList& infoList);
};

#endif  // TABLEMANAGER_H
