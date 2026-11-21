#ifndef APPLICANTSTATSPROJECT_THEMEMANAGER_H
#define APPLICANTSTATSPROJECT_THEMEMANAGER_H

#include <QColor>
#include <QObject>
#include <QString>
#include <QVariantList>
#include <QVariantMap>

class ThemeManager : public QObject
{
    Q_OBJECT

public:
    enum class Theme {
        Dark,
        Light,
        ClionLight
    };

    Q_ENUM(Theme)

    Q_PROPERTY(Theme currentTheme READ currentTheme WRITE setCurrentTheme NOTIFY themeChanged)


#ifndef APP_COLOR
#define APP_COLOR(name, darkValue, lightValue, clionLightValue) \
    Q_PROPERTY(QColor name READ name NOTIFY themeChanged) \
public: \
    QColor name() const { \
        switch (m_currentTheme) { \
            case Theme::Dark:      return QColor(darkValue); \
            case Theme::Light:     return QColor(lightValue); \
            case Theme::ClionLight: return QColor(clionLightValue); \
        } \
        return QColor(darkValue); \
    }\

    //  Фоны
    APP_COLOR(backgroundColor,      "#26282b", "#e8edf4", "#F7F8FA")
    APP_COLOR(panelColor,           "#191a1c", "#f2f5fa", "#FFFFFF")
    APP_COLOR(surfaceColor,         "#232527", "#f2f2f2", "#FFFFFF")
    APP_COLOR(surfaceLightColor,    "#2d2e32", "#e9ecf2", "#F5F6F8")
    APP_COLOR(surfaceHoverColor,    "#2f3033", "#e5ebf4", "#EFF1F5")
    APP_COLOR(surfaceSelectedColor, "#2d374e", "#dce5f3", "#E5EDFA")
    APP_COLOR(chartPlotColor,       "#202022", "#f4f6fa", "#FFFFFF")
    APP_COLOR(cardColor,            "#222326", "#f7f9fc", "#FFFFFF")

    //  Границы и разделители
    APP_COLOR(borderColor,        "#323232", "#cbd4e0", "#DFE2E8")
    APP_COLOR(dividerColor,       "#404040", "#dce2eb", "#E8EAF0")
    APP_COLOR(chartGridMainColor, "#3a3a3c", "#c5cfdd", "#D9DDE5")
    APP_COLOR(chartGridSubColor,  "#222223", "#e7ebf1", "#EFF1F5")

    // Акценты
    APP_COLOR(accentColor,        "#556da3", "#85a8f2", "#3574F0")
    APP_COLOR(accentHoverColor,   "#5f79b8", "#637daf", "#2865D8")
    APP_COLOR(accentPressedColor, "#48619c", "#455d91", "#1F55C2")
    APP_COLOR(accentLightColor,   "#6e8cd1", "#8298c2", "#6695F5")
    APP_COLOR(accentMutedColor,   "#607ab5", "#bac0cc", "#E5EDFA")

    // Текст
    APP_COLOR(textPrimaryColor,     "#eeeeee", "#252c38", "#1F2329")
    APP_COLOR(textSecondaryColor,   "#cccccc", "#505b6b", "#5C6370")
    APP_COLOR(textMutedColor,       "#999999", "#788496", "#858B98")
    APP_COLOR(textFaintColor,       "#6a6c70", "#a0a9b7", "#A5AAB4")
    APP_COLOR(textPlaceholderColor, "#5c6066", "#8994a4", "#A5AAB4")
    APP_COLOR(textOnAccentColor,    "#ffffff", "#ffffff", "#FFFFFF")

    // Семантический текст
    APP_COLOR(textSuccessColor,      "#91cd84", "#36865b", "#27864A")
    APP_COLOR(textSuccessMutedColor, "#87a586", "#5b9b76", "#51966A")
    APP_COLOR(textSuccessDimColor,   "#6a9960", "#83b394", "#78A987")
    APP_COLOR(textErrorColor,        "#e89d9d", "#c65f65", "#DB4B4B")
    APP_COLOR(textInfoColor,         "#7f9cc4", "#557eae", "#3574F0")
    APP_COLOR(textInfoMutedColor,    "#6c758a", "#7186a5", "#6488C5")
    APP_COLOR(textInfoDimColor,      "#557799", "#91a5c1", "#8AA4D0")
    APP_COLOR(textPurpleColor,       "#b891a2", "#9673ad", "#9B6BC5")

    // Семантические цвета
    APP_COLOR(successColor,      "#5cb180", "#5cb180", "#27864A")

    // Служебные
    APP_COLOR(iconColor,             "#aeaeae", "#65748a", "#6F7785")
    APP_COLOR(iconAltColor,          "#ced0d6", "#45546b", "#9BA2AE")
    APP_COLOR(overlayColor,          "#000000", "#252c38", "#66000000")
    APP_COLOR(progressGradientStart, "#4a8a4a", "#4a8a4a", "#3D965D")
    APP_COLOR(progressGradientEnd,   "#7ab87a", "#7ab87a", "#72B985")

    //Цвета ститистики
    APP_COLOR(statisticsPassingColor, "#d4a373", "#d4a373", "#C18A43")
    APP_COLOR(statisticsMaximumColor, "#7fb37f", "#7fb37f", "#41966A")
    APP_COLOR(statisticsMinimumColor, "#c47878", "#c47878", "#C85D63")
    APP_COLOR(statisticsAverageColor, "#7f9cc4", "#7f9cc4", "#4F79B8")
    APP_COLOR(statisticsMedianColor,  "#a37fc4", "#a37fc4", "#956BB5")

#undef APP_COLOR
#endif

public:
    explicit ThemeManager(QObject *parent = nullptr);


    Theme currentTheme() const;
    Q_INVOKABLE void setCurrentTheme(Theme theme);

private:
    Theme m_currentTheme = Theme::Dark;

signals:
    void themeChanged();
};

#endif  // APPLICANTSTATSPROJECT_THEMEMANAGER_H
