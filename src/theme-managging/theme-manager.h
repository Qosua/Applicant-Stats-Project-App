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
    Q_PROPERTY(QColor name READ name NOTIFY themeChanged)                         \
    public:                                                                       \
    QColor name() const {                                                         \
    return QColor(m_isLightTheme ? lightValue : darkValue);                       \
    }                                                                             \



    //  Фоны
    APP_COLOR(backgroundColor,      "#26282b", "#e8edf4")
    APP_COLOR(panelColor,           "#191a1c", "#f2f5fa")
    APP_COLOR(surfaceColor,         "#232527", "#ffffff")
    APP_COLOR(surfaceLightColor,    "#2d2e32", "#edf1f7")
    APP_COLOR(surfaceHoverColor,    "#2f3033", "#e5ebf4")
    APP_COLOR(surfaceSelectedColor, "#2d374e", "#dce5f3")
    APP_COLOR(chartPlotColor,       "#202022", "#f4f6fa")
    APP_COLOR(cardColor,            "#222326", "#f7f9fc")

    //  Границы и разделители
    APP_COLOR(borderColor,        "#323232", "#cbd4e0")
    APP_COLOR(dividerColor,       "#404040", "#dce2eb")
    APP_COLOR(chartGridMainColor, "#3a3a3c", "#c5cfdd")
    APP_COLOR(chartGridSubColor,  "#222223", "#e7ebf1")

    // Акценты
    APP_COLOR(accentColor,        "#556da3", "#6d89c7")
    APP_COLOR(accentHoverColor,   "#5f79b8", "#637daf")
    APP_COLOR(accentPressedColor, "#48619c", "#455d91")
    APP_COLOR(accentLightColor,   "#6e8cd1", "#8298c2")
    APP_COLOR(accentMutedColor,   "#607ab5", "#cfd6e3")

    // Текст
    APP_COLOR(textPrimaryColor,     "#eeeeee", "#252c38")
    APP_COLOR(textSecondaryColor,   "#cccccc", "#505b6b")
    APP_COLOR(textMutedColor,       "#999999", "#788496")
    APP_COLOR(textFaintColor,       "#6a6c70", "#a0a9b7")
    APP_COLOR(textPlaceholderColor, "#5c6066", "#8994a4")
    APP_COLOR(textOnAccentColor,    "#ffffff", "#ffffff")

    // Семантический текст
    APP_COLOR(textSuccessColor,      "#91cd84", "#36865b")
    APP_COLOR(textSuccessMutedColor, "#87a586", "#5b9b76")
    APP_COLOR(textSuccessDimColor,   "#6a9960", "#83b394")
    APP_COLOR(textErrorColor,        "#e89d9d", "#c65f65")
    APP_COLOR(textInfoColor,         "#7f9cc4", "#557eae")
    APP_COLOR(textInfoMutedColor,    "#6c758a", "#7186a5")
    APP_COLOR(textInfoDimColor,      "#557799", "#91a5c1")
    APP_COLOR(textPurpleColor,       "#b891a2", "#9673ad")

    // Семантические цвета
    APP_COLOR(successColor,      "#5cb180", "#5cb180")

    // Служебные
    APP_COLOR(iconColor,             "#aeaeae", "#65748a")
    APP_COLOR(iconAltColor,          "#ced0d6", "#45546b")
    APP_COLOR(overlayColor,          "#000000", "#252c38")
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
    Q_INVOKABLE void setLightTheme(bool enabled);

signals:
    void themeChanged();
};

#endif  // APPLICANTSTATSPROJECT_THEMEMANAGER_H
