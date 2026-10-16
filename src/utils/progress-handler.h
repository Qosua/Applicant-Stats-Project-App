#ifndef PROGRESS_HANDLER_H
#define PROGRESS_HANDLER_H

#include <QObject>

class ProgressHandler : public QObject {
    Q_OBJECT

    Q_PROPERTY(double progress READ getProgress CONSTANT)
    Q_PROPERTY(QString processName READ getProcessName CONSTANT)
    Q_PROPERTY(QString processMessage READ getProcessMessage CONSTANT)

    double processProgress = 0.0;  // in [0,1]
    QString currentProcessName;
    QString currentProcessMessage;

public:
    explicit ProgressHandler(QObject* parent = nullptr);

    void addProgressValue(const double& value);
    void setProgress(const double& newProgress);

    double getProgress() const;

    void setProcessName(const QString& name);
    void setProcessMessage(const QString& message);

    QString getProcessName() const;
    QString getProcessMessage() const;

signals:
    void progressChanged(const double&);
    void processChanged(const QString&);
    void message(const QString&);
    void processEnded(const QString&); //передаётся имя завершённого процесса
};

#endif  // PROGRESS_HANDLER_H
