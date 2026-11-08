#include <QDebug>
#include <QDir>
#include <QFile>
#include <QStandardPaths>

#include "app-paths-manager.h"

namespace {
const QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
}

const QString AppPathsManager::rootAppDataPath   = appDataPath + "/Applicants-Stats-Project";
const QString AppPathsManager::dbPath            = appDataPath + "/Applicants-Stats-Project/database.db";
const QString AppPathsManager::tablesStoragePath = appDataPath + "/Applicants-Stats-Project/data";
const QString AppPathsManager::cachePath         = appDataPath + "/Applicants-Stats-Project/cache";
const QString AppPathsManager::logsPath          = appDataPath + "/Applicants-Stats-Project/logs";
const QString AppPathsManager::downloadPath      = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);

AppPathsManager::AppPathsManager() {}

bool AppPathsManager::init() {

    bool result = true;

    if (!QDir().mkpath(rootAppDataPath)) {
        qCritical() << "AppPathsManager: failed to create root dir:" << rootAppDataPath;
        result = false;
    }

    // if (!QDir().mkpath(cachePath)) {
    //     qCritical() << "AppPathsManager: failed to create cache dir:" << cachePath;
    //     result = false;
    // }

    if (!QDir().mkpath(tablesStoragePath)) {
        qCritical() << "AppPathsManager: failed to create tables storage dir:" << tablesStoragePath;
        result = false;
    }

    if (!QDir().mkpath(logsPath)) {
        qCritical() << "AppPathsManager: failed to create logs dir:" << logsPath;
        result = false;
    }

    if (!QFile::exists(dbPath)) {
        qDebug() << "AppPathsManager: database file does not exist yet, will be created:" << dbPath;
    }

    if (result)
        qDebug() << "AppPathsManager: init OK, root:" << rootAppDataPath;
    else
        qCritical() << "AppPathsManager: INIT ERROR";

    return result;
}