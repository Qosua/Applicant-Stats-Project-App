#include <QDebug>
#include <QDir>
#include <QFile>
#include <QStandardPaths>

#include "app-paths-manager.h"

AppPathsManager::AppPathsManager() {}

bool AppPathsManager::init()
{
    bool result = true;

    if (!QDir().mkpath(rootAppDataPath)) {
        qCritical() << "AppPathsManager: failed to create root dir:" << rootAppDataPath;
        result = false;
    }

    if (!QDir().mkpath(cachePath)) {
        qCritical() << "AppPathsManager: failed to create cache dir:" << cachePath;
        result = false;
    }

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