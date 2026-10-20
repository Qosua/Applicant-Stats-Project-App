
//
// Created by artem on 04.10.2026.
//

#include "theme-manager.h"

ThemeManager::ThemeManager(QObject *parent) : QObject(parent) {

}

#define COLOR(name, darkValue, lightValue) \
    QColor ThemeManager::name() const { \
    return QColor(m_isLightTheme ? lightValue : darkValue); \
    }
    #include "theme-colors.def"

#undef COLOR

bool ThemeManager::lightTheme() const { return m_isLightTheme;}

void ThemeManager::setLightTheme(bool enabled) { if (m_isLightTheme == enabled)
    return;

    m_isLightTheme = enabled;
    emit themeChanged();
}



