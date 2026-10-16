#include "progress-handler.h"

ProgressHandler::ProgressHandler(QObject* parent) : QObject{parent} {}

void ProgressHandler::addProgressValue(const double& value) { setProgress(getProgress() + value); }

void ProgressHandler::setProgress(const double& newProgress) {
    processProgress = newProgress;
    if (processProgress > 1) {
	processProgress = 1;
	emit processEnded(currentProcessName);
    }

    emit progressChanged(processProgress);
}

double ProgressHandler::getProgress() const { return processProgress; }

bool ProgressHandler::isActive() const { return active; }

void ProgressHandler::setProcessName(const QString& name) {
    /*
     * todo
     * возможно было бы удобнее, если при смене
     * названия процесса (теоретически начало нового)
     * метод обнулял текущий прогресс
     */

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
