#ifndef APPLICANTSTATSPROJECT_APPPATHSMANAGER_H
#define APPLICANTSTATSPROJECT_APPPATHSMANAGER_H

#include <QString>
#include <QStandardPaths>

class AppPathsManager {

public:
    AppPathsManager();

    static bool init();

signals:
    void initCacheManager();

    inline static const QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    inline static const QString rootAppDataPath = appDataPath + "/Applicants-Stats-Project/";
    inline static const QString dbPath = appDataPath + "/Applicants-Stats-Project/database.db";
    inline static const QString tablesStoragePath = appDataPath + "/Applicants-Stats-Project/data";
    inline static const QString cachePath = appDataPath + "/Applicants-Stats-Project/cache/";
    inline static const QString logsPath = appDataPath + "/Applicants-Stats-Project/logs/";
    inline static const QString downloadPath = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
};

#endif  // APPLICANTSTATSPROJECT_APPPATHSMANAGER_H
