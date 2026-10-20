//
// Created by artem on 04.10.2026.
//

#ifndef APPLICANTSTATSPROJECT_THEMEMANAGER_H
#define APPLICANTSTATSPROJECT_THEMEMANAGER_H


#include <QColor>
#include <QObject>
#include <QString>
#include <QVariantList>
#include <QVariantMap>



class ThemeManager : public QObject {

    Q_OBJECT

    #define COLOR(name, darkValue, lightValue) \
    Q_PROPERTY(QColor name READ name NOTIFY themeChanged)

    #include "theme-colors.def"

    #undef COLOR

    //изсенение темы
    Q_PROPERTY(bool lightTheme READ lightTheme WRITE setLightTheme NOTIFY themeChanged)






public:
    explicit ThemeManager(QObject *parent = nullptr);

#define COLOR(name, darkValue, lightValue) \
    QColor name() const;

    #include "theme-colors.def"

    #undef COLOR

    //изменение темы
    bool lightTheme() const;


    void setLightTheme(bool enabled);



signals:
    void themeChanged();

private:
    bool m_isLightTheme = false;


};

#endif  // APPLICANTSTATSPROJECT_THEMEMANAGER_H
