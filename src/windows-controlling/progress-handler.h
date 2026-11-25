#ifndef PROGRESS_HANDLER_H
#define PROGRESS_HANDLER_H

#include <QObject>
#include <QString>

class ProgressHandler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double progress READ getProgress NOTIFY progressChanged CONSTANT)
    Q_PROPERTY(QString processName READ getProcessName NOTIFY processChanged CONSTANT)
    Q_PROPERTY(QString processMessage READ getProcessMessage NOTIFY messageChanged CONSTANT)
    Q_PROPERTY(bool active READ isActive NOTIFY activeChanged CONSTANT)

    double processProgress = 0.2; // [0,1]
    bool active = false;
    QString currentProcessName = "Unknow Process";
    QString currentProcessMessage = "None";

public:
    explicit ProgressHandler(QObject* parent = nullptr);

    void addProgressValue(const double& value);
    void setProgress(const double& newProgress);
    void setActive(const bool& arg);

    [[nodiscard]] double getProgress() const;
    [[nodiscard]] bool isActive() const;

    void setProcessName(const QString& name);
    void setProcessMessage(const QString& message);

    [[nodiscard]] QString getProcessName() const;
    [[nodiscard]] QString getProcessMessage() const;

signals:
    void progressChanged(const double&);
    void processChanged(const QString&);
    void messageChanged(const QString&);
    void activeChanged(const bool&);
};

#endif // PROGRESS_HANDLER_H
