#ifndef APPLICANTSTATSPROJECT_APPPATHSMANAGER_H
#define APPLICANTSTATSPROJECT_APPPATHSMANAGER_H

#include <QString>

class AppPathsManager {

public:
    AppPathsManager();

    static bool init();

signals:
    void initCacheManager();

public:
    static const QString dbPath;
    static const QString rootAppDataPath;
    static const QString tablesStoragePath;
    static const QString cachePath;
    static const QString logsPath;
    static const QString downloadPath;
};

#endif  // APPLICANTSTATSPROJECT_APPPATHSMANAGER_H
