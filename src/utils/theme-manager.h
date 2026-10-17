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

    // Фон
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY
                   backgroundColorChanged)
    Q_PROPERTY(QColor panelColor READ panelColor WRITE setPanelColor NOTIFY panelColorChanged)
    Q_PROPERTY(
        QColor surfaceColor READ surfaceColor WRITE setSurfaceColor NOTIFY surfaceColorChanged)
    Q_PROPERTY(QColor surfaceHoverColor READ surfaceHoverColor WRITE setSurfaceHoverColor NOTIFY
                   surfaceHoverColorChanged)
    Q_PROPERTY(QColor surfaceSelectedColor READ surfaceSelectedColor WRITE setSurfaceSelectedColor
                   NOTIFY surfaceSelectedColorChanged)
    Q_PROPERTY(QColor chartPlotColor READ chartPlotColor WRITE setChartPlotColor NOTIFY
                   chartPlotColorChanged)
    Q_PROPERTY(QColor cardColor READ cardColor WRITE setCardColor NOTIFY cardColorChanged)

    // Границы, разделители
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(
        QColor dividerColor READ dividerColor WRITE setDividerColor NOTIFY dividerColorChanged)
    Q_PROPERTY(QColor chartGridMainColor READ chartGridMainColor WRITE setChartGridMainColor NOTIFY
                   chartGridMainColorChanged)
    Q_PROPERTY(QColor chartGridSubColor READ chartGridSubColor WRITE setChartGridSubColor NOTIFY
                   chartGridSubColorChanged)

    // Акценты
    Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY accentColorChanged)
    Q_PROPERTY(QColor accentHoverColor READ accentHoverColor WRITE setAccentHoverColor NOTIFY
                   accentHoverColorChanged)
    Q_PROPERTY(QColor accentPressedColor READ accentPressedColor WRITE setAccentPressedColor NOTIFY
                   accentPressedColorChanged)
    Q_PROPERTY(QColor accentLightColor READ accentLightColor WRITE setAccentLightColor NOTIFY
                   accentLightColorChanged)
    Q_PROPERTY(QColor accentMutedColor READ accentMutedColor WRITE setAccentMutedColor NOTIFY
                   accentMutedColorChanged)

    // Текст
    Q_PROPERTY(QColor textPrimaryColor READ textPrimaryColor WRITE setTextPrimaryColor NOTIFY
                   textPrimaryColorChanged)
    Q_PROPERTY(QColor textSecondaryColor READ textSecondaryColor WRITE setTextSecondaryColor NOTIFY
                   textSecondaryColorChanged)
    Q_PROPERTY(QColor textMutedColor READ textMutedColor WRITE setTextMutedColor NOTIFY
                   textMutedColorChanged)
    Q_PROPERTY(QColor textFaintColor READ textFaintColor WRITE setTextFaintColor NOTIFY
                   textFaintColorChanged)
    Q_PROPERTY(QColor textPlaceholderColor READ textPlaceholderColor WRITE setTextPlaceholderColor
                   NOTIFY textPlaceholderColorChanged)
    Q_PROPERTY(QColor textOnAccentColor READ textOnAccentColor WRITE setTextOnAccentColor NOTIFY
                   textOnAccentColorChanged)

    // Семантический текст
    Q_PROPERTY(QColor textSuccessColor READ textSuccessColor WRITE setTextSuccessColor NOTIFY
                   textSuccessColorChanged)
    Q_PROPERTY(QColor textSuccessMutedColor READ textSuccessMutedColor WRITE
                   setTextSuccessMutedColor NOTIFY textSuccessMutedColorChanged)
    Q_PROPERTY(QColor textSuccessDimColor READ textSuccessDimColor WRITE setTextSuccessDimColor
                   NOTIFY textSuccessDimColorChanged)
    Q_PROPERTY(QColor textErrorColor READ textErrorColor WRITE setTextErrorColor NOTIFY
                   textErrorColorChanged)
    Q_PROPERTY(
        QColor textInfoColor READ textInfoColor WRITE setTextInfoColor NOTIFY textInfoColorChanged)
    Q_PROPERTY(QColor textInfoMutedColor READ textInfoMutedColor WRITE setTextInfoMutedColor NOTIFY
                   textInfoMutedColorChanged)
    Q_PROPERTY(QColor textInfoDimColor READ textInfoDimColor WRITE setTextInfoDimColor NOTIFY
                   textInfoDimColorChanged)
    Q_PROPERTY(QColor textPurpleColor READ textPurpleColor WRITE setTextPurpleColor NOTIFY
                   textPurpleColorChanged)

    // Семантические
    Q_PROPERTY(
        QColor successColor READ successColor WRITE setSuccessColor NOTIFY successColorChanged)
    Q_PROPERTY(QColor successLightColor READ successLightColor WRITE setSuccessLightColor NOTIFY
                   successLightColorChanged)
    Q_PROPERTY(QColor errorColor READ errorColor WRITE setErrorColor NOTIFY errorColorChanged)
    Q_PROPERTY(
        QColor warningColor READ warningColor WRITE setWarningColor NOTIFY warningColorChanged)
    Q_PROPERTY(QColor infoColor READ infoColor WRITE setInfoColor NOTIFY infoColorChanged)
    Q_PROPERTY(QColor purpleColor READ purpleColor WRITE setPurpleColor NOTIFY purpleColorChanged)

    // Семантические палитры
    Q_PROPERTY(QColor chartColor1 READ chartColor1 WRITE setChartColor1 NOTIFY chartPaletteChanged)
    Q_PROPERTY(QColor chartColor2 READ chartColor2 WRITE setChartColor2 NOTIFY chartPaletteChanged)
    Q_PROPERTY(QColor chartColor3 READ chartColor3 WRITE setChartColor3 NOTIFY chartPaletteChanged)
    Q_PROPERTY(QColor chartColor4 READ chartColor4 WRITE setChartColor4 NOTIFY chartPaletteChanged)
    Q_PROPERTY(QColor chartColor5 READ chartColor5 WRITE setChartColor5 NOTIFY chartPaletteChanged)

    // Служебные
    Q_PROPERTY(QColor iconColor READ iconColor WRITE setIconColor NOTIFY iconColorChanged)
    Q_PROPERTY(
        QColor iconAltColor READ iconAltColor WRITE setIconAltColor NOTIFY iconAltColorChanged)
    Q_PROPERTY(
        QColor overlayColor READ overlayColor WRITE setOverlayColor NOTIFY overlayColorChanged)

public:
    explicit ThemeManager(QObject *parent = nullptr);

    // фон

    QColor backgroundColor() const;
    QColor panelColor() const;
    QColor surfaceColor() const;
    QColor surfaceHoverColor() const;
    QColor surfaceSelectedColor() const;
    QColor chartPlotColor() const;
    QColor cardColor() const;

    // Границы, разделители

    QColor borderColor() const;
    QColor dividerColor() const;
    QColor chartGridMainColor() const;
    QColor chartGridSubColor() const;

    // Выделители (акцентные цвета)

    QColor accentColor() const;
    QColor accentHoverColor() const;
    QColor accentPressedColor() const;
    QColor accentLightColor() const;
    QColor accentMutedColor() const;

    // Текст
    QColor textPrimaryColor() const;
    QColor textSecondaryColor() const;
    QColor textMutedColor() const;
    QColor textFaintColor() const;
    QColor textPlaceholderColor() const;
    QColor textOnAccentColor() const;

    // Семантически цвета текста
    QColor textSuccessColor() const;
    QColor textSuccessMutedColor() const;
    QColor textSuccessDimColor() const;
    QColor textErrorColor() const;
    QColor textInfoColor() const;
    QColor textInfoMutedColor() const;
    QColor textInfoDimColor() const;
    QColor textPurpleColor() const;

    // Семантические
    QColor successColor() const;
    QColor successLightColor() const;
    QColor errorColor() const;
    QColor warningColor() const;
    QColor infoColor() const;
    QColor purpleColor() const;

    // Семантичесние палитра
    QColor chartColor1() const;
    QColor chartColor2() const;
    QColor chartColor3() const;
    QColor chartColor4() const;
    QColor chartColor5() const;

    // служебные
    QColor iconColor() const;     // #aeaeae
    QColor iconAltColor() const;  // #ced0d6
    QColor overlayColor() const;  // #000000

    // Палитры
    Q_INVOKABLE QVariantList chartBarsPalette() const;
    Q_INVOKABLE QVariantMap progressGradient() const;
    Q_INVOKABLE QVariantList chartPalette() const;

    // Фон
    void setBackgroundColor(const QColor &color);
    void setPanelColor(const QColor &color);
    void setSurfaceColor(const QColor &color);
    void setSurfaceHoverColor(const QColor &color);
    void setSurfaceSelectedColor(const QColor &color);
    void setChartPlotColor(const QColor &color);
    void setCardColor(const QColor &color);

    // Границы, разделители
    void setBorderColor(const QColor &color);
    void setDividerColor(const QColor &color);
    void setChartGridMainColor(const QColor &color);
    void setChartGridSubColor(const QColor &color);

    // Акценты
    void setAccentColor(const QColor &color);
    void setAccentHoverColor(const QColor &color);
    void setAccentPressedColor(const QColor &color);
    void setAccentLightColor(const QColor &color);
    void setAccentMutedColor(const QColor &color);

    // Текст
    void setTextPrimaryColor(const QColor &color);
    void setTextSecondaryColor(const QColor &color);
    void setTextMutedColor(const QColor &color);
    void setTextFaintColor(const QColor &color);
    void setTextPlaceholderColor(const QColor &color);
    void setTextOnAccentColor(const QColor &color);

    // Семантический текст
    void setTextSuccessColor(const QColor &color);
    void setTextSuccessMutedColor(const QColor &color);
    void setTextSuccessDimColor(const QColor &color);
    void setTextErrorColor(const QColor &color);
    void setTextInfoColor(const QColor &color);
    void setTextInfoMutedColor(const QColor &color);
    void setTextInfoDimColor(const QColor &color);
    void setTextPurpleColor(const QColor &color);

    // Семантические
    void setSuccessColor(const QColor &color);
    void setSuccessLightColor(const QColor &color);
    void setErrorColor(const QColor &color);
    void setWarningColor(const QColor &color);
    void setInfoColor(const QColor &color);
    void setPurpleColor(const QColor &color);

    // Семантические палитра
    void setChartColor1(const QColor &color);
    void setChartColor2(const QColor &color);
    void setChartColor3(const QColor &color);
    void setChartColor4(const QColor &color);
    void setChartColor5(const QColor &color);

    // Служебные
    void setIconColor(const QColor &color);
    void setIconAltColor(const QColor &color);
    void setOverlayColor(const QColor &color);

signals:
    void backgroundColorChanged();
    void panelColorChanged();
    void surfaceColorChanged();
    void surfaceHoverColorChanged();
    void surfaceSelectedColorChanged();
    void chartPlotColorChanged();
    void cardColorChanged();

    void borderColorChanged();
    void dividerColorChanged();
    void chartGridMainColorChanged();
    void chartGridSubColorChanged();

    void accentColorChanged();
    void accentHoverColorChanged();
    void accentPressedColorChanged();
    void accentLightColorChanged();
    void accentMutedColorChanged();

    void textPrimaryColorChanged();
    void textSecondaryColorChanged();
    void textMutedColorChanged();
    void textFaintColorChanged();
    void textPlaceholderColorChanged();
    void textOnAccentColorChanged();

    void textSuccessColorChanged();
    void textSuccessMutedColorChanged();
    void textSuccessDimColorChanged();
    void textErrorColorChanged();
    void textInfoColorChanged();
    void textInfoMutedColorChanged();
    void textInfoDimColorChanged();
    void textPurpleColorChanged();

    void successColorChanged();
    void successLightColorChanged();
    void errorColorChanged();
    void warningColorChanged();
    void infoColorChanged();
    void purpleColorChanged();

    void chartPaletteChanged();

    void iconColorChanged();
    void iconAltColorChanged();
    void overlayColorChanged();

private:
    //  Фоны
    QColor m_backgroundColor;       // #26282b
    QColor m_panelColor;            // #191a1c
    QColor m_surfaceColor;          // #232527
    QColor m_surfaceHoverColor;     // #2f3033
    QColor m_surfaceSelectedColor;  // #2d374e
    QColor m_chartPlotColor;        // #202022
    QColor m_cardColor;

    //  Границы и разделители
    QColor m_borderColor;         // #323232
    QColor m_dividerColor;        // #404040
    QColor m_chartGridMainColor;  // #3a3a3c
    QColor m_chartGridSubColor;   // #222223

    // Акценты
    QColor m_accentColor;         // #556da3
    QColor m_accentHoverColor;    // #5f79b8
    QColor m_accentPressedColor;  // #48619c
    QColor m_accentLightColor;    // #6e8cd1
    QColor m_accentMutedColor;

    // Текст
    QColor m_textPrimaryColor;      // #eeeeee
    QColor m_textSecondaryColor;    // #cccccc
    QColor m_textMutedColor;        // #999999
    QColor m_textFaintColor;        // #6a6c70
    QColor m_textPlaceholderColor;  // #5c6066
    QColor m_textOnAccentColor;     // #ffffff

    // Семантический текст
    QColor m_textSuccessColor;       // #91cd84
    QColor m_textSuccessMutedColor;  // #87a586
    QColor m_textSuccessDimColor;    // #6a9960
    QColor m_textErrorColor;         // #e89d9d
    QColor m_textInfoColor;          // #7f9cc4
    QColor m_textInfoMutedColor;     // #6c758a
    QColor m_textInfoDimColor;       // #557799
    QColor m_textPurpleColor;        // #b891a2

    // Семантические цвета
    QColor m_successColor;       // #5cb180
    QColor m_successLightColor;  // #7fb37f
    QColor m_errorColor;         // #c47878
    QColor m_warningColor;       // #d4a373
    QColor m_infoColor;          // #7f9cc4
    QColor m_purpleColor;        // #a37fc4

    // Семантическая палитра
    QColor m_chartColor1;  // #d4a373
    QColor m_chartColor2;  // #7fb37f
    QColor m_chartColor3;  // #c47878
    QColor m_chartColor4;  // #7f9cc4
    QColor m_chartColor5;  // #a37fc4

    // Служебные
    QColor m_iconColor;     // #aeaeae
    QColor m_iconAltColor;  // #ced0d6
    QColor m_overlayColor;  // #000000
};

#endif  // APPLICANTSTATSPROJECT_THEMEMANAGER_H
