#ifndef LOGGER_H
#define LOGGER_H

#include <QDir>
#include <QFile>
#include <QString>
#include <QTextStream>

class Logger {

public:
    static void initLog();
    static void logHandler(QtMsgType type, const QMessageLogContext& context, const QString& text);

private:
    static inline QFile logFile;
    static inline QTextStream stream;

    Logger() = default;
    Logger(const Logger&) = delete;

    static bool handleType(const QtMsgType& type);
    static void handleFatal(const QMessageLogContext& context, const QString& text);
};

#endif  // LOGGER_H
