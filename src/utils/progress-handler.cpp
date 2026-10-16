#include "progress-handler.h"

ProgressHandler::ProgressHandler(QObject* parent) : QObject{parent} {}

void ProgressHandler::addProgressValue(const double& value) { setProgress(getProgress() + value); }

void ProgressHandler::setProgress(const double& newProgress) {

    if (processProgress == newProgress)
        return;

    // заключает значение newProgress в [0, 1]
    processProgress = std::max(std::min(newProgress, 1.0), 0.0);

    emit progressChanged(processProgress);
}

double ProgressHandler::getProgress() const { return processProgress; }

bool ProgressHandler::isActive() const { return active; }

void ProgressHandler::setProcessName(const QString& name) {

    currentProcessName = name;
    emit processChanged(currentProcessName);
}

void ProgressHandler::setProcessMessage(const QString& message) {

    currentProcessMessage = message;
    emit this->message(currentProcessMessage);
}

QString ProgressHandler::getProcessName() const { return currentProcessName; }

QString ProgressHandler::getProcessMessage() const { return currentProcessMessage; }

void ProgressHandler::setActive(const bool& arg) { active = arg; }
