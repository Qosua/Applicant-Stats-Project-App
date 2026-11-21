#include "theme-manager.h"

ThemeManager::ThemeManager(QObject *parent) : QObject(parent) {}

ThemeManager::Theme ThemeManager::currentTheme() const
{
    return m_currentTheme;
}
void ThemeManager::setCurrentTheme(Theme theme)
{
    if (m_currentTheme == theme) {
        return;
    }

    m_currentTheme = theme;
    emit themeChanged();
}




