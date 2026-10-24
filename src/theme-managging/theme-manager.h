#ifndef APPLICANTSTATSPROJECT_THEMEMANAGER_H
#define APPLICANTSTATSPROJECT_THEMEMANAGER_H

#include <QColor>
#include <QObject>
#include <QString>
#include <QVariantList>
#include <QVariantMap>

class ThemeManager : public QObject {

    Q_OBJECT

    Q_PROPERTY(bool isLightTheme READ isLightTheme WRITE setLightTheme NOTIFY themeChanged)
    bool m_isLightTheme = false;

#ifndef APP_COLOR
#define APP_COLOR(name, darkValue, lightValue)                                    \
    Q_PROPERTY(QColor name READ name WRITE name##Setter)                          \
private:                                                                          \
    QColor m_##name = (m_isLightTheme ? lightValue : darkValue);                  \
public:                                                                           \
    QColor name() const { return m_##name; }                                      \
private:                                                                          \
    void name##Setter(const QColor newColor) {                                    \
        m_##name = newColor;                                                      \
    }


    //  Фоны
    APP_COLOR(backgroundColor,      "#26282b", "#ffffff")
    APP_COLOR(panelColor,           "#191a1c", "#ffffff")
    APP_COLOR(surfaceColor,         "#232527", "#ffffff")
    APP_COLOR(surfaceLightColor,    "#2d2e32", "#ffffff")
    APP_COLOR(surfaceHoverColor,    "#2f3033", "#ffffff")
    APP_COLOR(surfaceSelectedColor, "#2d374e", "#ffffff")
    APP_COLOR(chartPlotColor,       "#202022", "#ffffff")
    APP_COLOR(cardColor,            "#222326", "#ffffff")

    //  Границы и разделители
    APP_COLOR(borderColor,        "#323232", "#ffffff")
    APP_COLOR(dividerColor,       "#404040", "#ffffff")
    APP_COLOR(chartGridMainColor, "#3a3a3c", "#ffffff")
    APP_COLOR(chartGridSubColor,  "#222223", "#ffffff")

    // Акценты
    APP_COLOR(accentColor,        "#556da3", "#ffffff")
    APP_COLOR(accentHoverColor,   "#5f79b8", "#ffffff")
    APP_COLOR(accentPressedColor, "#48619c", "#ffffff")
    APP_COLOR(accentLightColor,   "#6e8cd1", "#ffffff")
    APP_COLOR(accentMutedColor,   "#607ab5", "#ffffff")

    // Текст
    APP_COLOR(textPrimaryColor,     "#eeeeee", "#ffffff")
    APP_COLOR(textSecondaryColor,   "#cccccc", "#ffffff")
    APP_COLOR(textMutedColor,       "#999999", "#ffffff")
    APP_COLOR(textFaintColor,       "#6a6c70", "#ffffff")
    APP_COLOR(textPlaceholderColor, "#5c6066", "#ffffff")
    APP_COLOR(textOnAccentColor,    "#ffffff", "#ffffff")

    // Семантический текст
    APP_COLOR(textSuccessColor,      "#91cd84", "#ffffff")
    APP_COLOR(textSuccessMutedColor, "#87a586", "#ffffff")
    APP_COLOR(textSuccessDimColor,   "#6a9960", "#ffffff")
    APP_COLOR(textErrorColor,        "#e89d9d", "#ffffff")
    APP_COLOR(textInfoColor,         "#7f9cc4", "#ffffff")
    APP_COLOR(textInfoMutedColor,    "#6c758a", "#ffffff")
    APP_COLOR(textInfoDimColor,      "#557799", "#ffffff")
    APP_COLOR(textPurpleColor,       "#b891a2", "#ffffff")

    // Семантические цвета
    APP_COLOR(successColor,      "#5cb180", "#ffffff")

    // Служебные
    APP_COLOR(iconColor,             "#aeaeae", "#ffffff")
    APP_COLOR(iconAltColor,          "#ced0d6", "#ffffff")
    APP_COLOR(overlayColor,          "#000000", "#ffffff")
    APP_COLOR(progressGradientStart, "#4a8a4a", "#4a8a4a")
    APP_COLOR(progressGradientEnd,   "#7ab87a", "#7ab87a")

    //Цвета ститистики
    APP_COLOR(statisticsPassingColor, "#d4a373", "#d4a373")
    APP_COLOR(statisticsMaximumColor, "#7fb37f", "#7fb37f")
    APP_COLOR(statisticsMinimumColor, "#c47878", "#c47878")
    APP_COLOR(statisticsAverageColor, "#7f9cc4", "#7f9cc4")
    APP_COLOR(statisticsMedianColor,  "#a37fc4", "#a37fc4")

#undef APP_COLOR
#endif

public:
    explicit ThemeManager(QObject *parent = nullptr);

    bool isLightTheme() const;
    void setLightTheme(bool enabled);

signals:
    void themeChanged();
};

#endif  // APPLICANTSTATSPROJECT_THEMEMANAGER_H
