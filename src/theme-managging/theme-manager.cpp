#include "theme-manager.h"

ThemeManager::ThemeManager(QObject *parent) : QObject(parent) {}

bool ThemeManager::isLightTheme() const { return m_isLightTheme; }

void ThemeManager::setLightTheme(bool enabled) {

    if (m_isLightTheme == enabled)
        return;

    m_isLightTheme = enabled;
    emit themeChanged();
}



