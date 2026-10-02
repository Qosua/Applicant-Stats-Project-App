#include "logger.h"

#include "app-paths-manager.h"

void Logger::initLog()
{
    if(logFile.isOpen()) return; //if developer wants reopen current log file. todo: Qosua, pls check this moment

    quint64 unix_t = QDateTime::currentSecsSinceEpoch();

    //added unix time postfix cus of more then one session per day
    logFile.setFileName(AppPathsManager::appLogsPath + "/" + "[" + QString(__DATE__) + "]_" + QString::number(unix_t) + ".txt");
	logFile.open(QIODevice::ReadOnly | QIODevice::Append | QIODevice::Text);
	stream.setDevice(&logFile);

	stream << "SESSION SATRTED\n";
}

void Logger::logHandler(QtMsgType type, const QMessageLogContext &context, const QString &text)
{
    stream << "[" + QTime::currentTime().toString() + "] ";

    if(!handleType(type))
    {

	    stream << "(" << context.file << ":" << context.line << ") " << text << "\n";
	    stream.flush();
    }
    else
    {
	    handleFatal(context,text);
    }
}

bool Logger::handleType(const QtMsgType &type)
{
    bool fatal_flag = false;
    switch (type)
    {
	case QtMsgType::QtDebugMsg    : { Logger::stream << "[DEBUG]"; }break;
	case QtMsgType::QtInfoMsg     : { Logger::stream << "[INFO ]"; }break;
	case QtMsgType::QtWarningMsg  : { Logger::stream << "[WARN ]"; }break;
	case QtMsgType::QtCriticalMsg : { Logger::stream << "[CRIT ]"; }break;
	case QtMsgType::QtFatalMsg    : { fatal_flag = true; }break;
	default:
	    break;
    }

    return fatal_flag;
}

void Logger::handleFatal(const QMessageLogContext &context, const QString &text)
{
    stream << "[FATAL]" << "(" << context.file << ":" << context.line << ") " << text << "\n";
    logFile.close();
    stream.flush();
    abort();
}

