#ifndef PROGRESS_HANDLER_H
#define PROGRESS_HANDLER_H

#include <QObject>

class ProgressHandler : public QObject {
    Q_OBJECT

    Q_PROPERTY(double progress READ getProgress CONSTANT)
    Q_PROPERTY(QString processName READ getProcessName CONSTANT)
    Q_PROPERTY(QString processMessage READ getProcessMessage CONSTANT)
    Q_PROPERTY(bool active READ isActive CONSTANT)

    double processProgress = 0.2;  // [0,1]
    bool active = true;
    QString currentProcessName = "Unknow Process";
    QString currentProcessMessage = "None";

public:
    explicit ProgressHandler(QObject* parent = nullptr);

    void addProgressValue(const double& value);
    void setProgress(const double& newProgress);
    void setActive(const bool& arg);

    double getProgress() const;
    bool isActive() const;

    void setProcessName(const QString& name);
    void setProcessMessage(const QString& message);

    QString getProcessName() const;
    QString getProcessMessage() const;

signals:
    void progressChanged(const double&);
    void processChanged(const QString&);
    void message(const QString&);
};

#endif  // PROGRESS_HANDLER_H
