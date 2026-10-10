#include "logger.h"

#include "app-paths-manager.h"

void Logger::initLog() {

    if (logFile.isOpen())
	return;

    // unix_t for naming log file for each program session
    quint64 unix_t = QDateTime::currentSecsSinceEpoch();

    logFile.setFileName(AppPathsManager::appLogsPath + "/" + QString(__DATE__).replace(" ", "-")
                        + "_" + QString::number(unix_t) + ".log");
    logFile.open(QIODevice::ReadOnly | QIODevice::Append | QIODevice::Text);

    stream.setDevice(&logFile);
    stream << "[" + QTime::currentTime().toString() + "] " << "SESSION SATRTED" << "\n";
}

void Logger::logHandler(QtMsgType type, const QMessageLogContext& context, const QString& text) {

    if (handleType(type)) {

	stream << "[" + QTime::currentTime().toString() + "] ";
	stream << "(" << context.file << ":" << context.line << ") " << text << "\n";
	stream.flush();
    } else {
	handleFatal(context, text);
    }
}

bool Logger::handleType(const QtMsgType& type) {

    switch (type) {
	case QtMsgType::QtDebugMsg: {
	    stream << "[D] ";
	} break;
	case QtMsgType::QtInfoMsg: {
	    stream << "[I] ";
	} break;
	case QtMsgType::QtWarningMsg: {
	    stream << "[W] ";
	} break;
	case QtMsgType::QtCriticalMsg: {
	    stream << "[C] ";
	} break;
	case QtMsgType::QtFatalMsg: {
	    stream << "[FATAL] ";
	    return false;
	} break;
	default:
	    break;
    }

    return true;
}

void Logger::handleFatal(const QMessageLogContext& context, const QString& text) {
    stream << "[" + QTime::currentTime().toString() + "] ";
    stream << "(" << context.file << ":" << context.line << ") " << text << "\n";
    logFile.close();
    stream.flush();
    abort();
}
