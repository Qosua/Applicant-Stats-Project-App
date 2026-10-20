#include "theme-manager.h"

ThemeManager::ThemeManager(QObject *parent) : QObject(parent) {
    // Фон
    m_backgroundColor = QColor("#26282b");
    m_panelColor = QColor("#191a1c");
    m_surfaceColor = QColor("#232527");
    m_surfaceHoverColor = QColor("#2f3033");
    m_surfaceSelectedColor = QColor("#2d374e");
    m_chartPlotColor = QColor("#202022");
    m_cardColor = QColor("#222326");

    // Границы, разделители
    m_borderColor = QColor("#323232");
    m_dividerColor = QColor("#404040");
    m_chartGridMainColor = QColor("#3a3a3c");
    m_chartGridSubColor = QColor("#222223");

    // Акценты
    m_accentColor = QColor("#556da3");
    m_accentHoverColor = QColor("#5f79b8");
    m_accentPressedColor = QColor("#48619c");
    m_accentLightColor = QColor("#6e8cd1");
    m_accentMutedColor = QColor("#607ab5");

    // Текст
    m_textPrimaryColor = QColor("#eeeeee");
    m_textSecondaryColor = QColor("#cccccc");
    m_textMutedColor = QColor("#999999");
    m_textFaintColor = QColor("#6a6c70");
    m_textPlaceholderColor = QColor("#5c6066");
    m_textOnAccentColor = QColor("#ffffff");

    // Семантический текст
    m_textSuccessColor = QColor("#91cd84");
    m_textSuccessMutedColor = QColor("#87a586");
    m_textSuccessDimColor = QColor("#6a9960");
    m_textErrorColor = QColor("#e89d9d");
    m_textInfoColor = QColor("#7f9cc4");
    m_textInfoMutedColor = QColor("#6c758a");
    m_textInfoDimColor = QColor("#557799");
    m_textPurpleColor = QColor("#b891a2");

    // Семантические
    m_successColor = QColor("#5cb180");
    m_successLightColor = QColor("#7fb37f");
    m_errorColor = QColor("#c47878");
    m_warningColor = QColor("#d4a373");
    m_infoColor = QColor("#7f9cc4");
    m_purpleColor = QColor("#a37fc4");

    // Семантическая палитра
    m_chartColor1 = QColor("#d4a373");
    m_chartColor2 = QColor("#7fb37f");
    m_chartColor3 = QColor("#c47878");
    m_chartColor4 = QColor("#7f9cc4");
    m_chartColor5 = QColor("#a37fc4");

    // Служебные
    m_iconColor = QColor("#aeaeae");
    m_iconAltColor = QColor("#ced0d6");
    m_overlayColor = QColor("#000000");
}

// Геттеры

// Фон

QColor ThemeManager::backgroundColor() const { return m_backgroundColor; }
QColor ThemeManager::panelColor() const { return m_panelColor; }
QColor ThemeManager::surfaceColor() const { return m_surfaceColor; }
QColor ThemeManager::surfaceHoverColor() const { return m_surfaceHoverColor; }
QColor ThemeManager::surfaceSelectedColor() const { return m_surfaceSelectedColor; }
QColor ThemeManager::chartPlotColor() const { return m_chartPlotColor; }
QColor ThemeManager::cardColor() const { return m_cardColor; }

// Границы, разделители

QColor ThemeManager::borderColor() const { return m_borderColor; }
QColor ThemeManager::dividerColor() const { return m_dividerColor; }
QColor ThemeManager::chartGridMainColor() const { return m_chartGridMainColor; }
QColor ThemeManager::chartGridSubColor() const { return m_chartGridSubColor; }

// Акценты

QColor ThemeManager::accentColor() const { return m_accentColor; }
QColor ThemeManager::accentHoverColor() const { return m_accentHoverColor; }
QColor ThemeManager::accentPressedColor() const { return m_accentPressedColor; }
QColor ThemeManager::accentLightColor() const { return m_accentLightColor; }
QColor ThemeManager::accentMutedColor() const { return m_accentMutedColor; }

// Текст

QColor ThemeManager::textPrimaryColor() const { return m_textPrimaryColor; }
QColor ThemeManager::textSecondaryColor() const { return m_textSecondaryColor; }
QColor ThemeManager::textMutedColor() const { return m_textMutedColor; }
QColor ThemeManager::textFaintColor() const { return m_textFaintColor; }
QColor ThemeManager::textPlaceholderColor() const { return m_textPlaceholderColor; }
QColor ThemeManager::textOnAccentColor() const { return m_textOnAccentColor; }

// Семантический текст

QColor ThemeManager::textSuccessColor() const { return m_textSuccessColor; }
QColor ThemeManager::textSuccessMutedColor() const { return m_textSuccessMutedColor; }
QColor ThemeManager::textSuccessDimColor() const { return m_textSuccessDimColor; }
QColor ThemeManager::textErrorColor() const { return m_textErrorColor; }
QColor ThemeManager::textInfoColor() const { return m_textInfoColor; }
QColor ThemeManager::textInfoMutedColor() const { return m_textInfoMutedColor; }
QColor ThemeManager::textInfoDimColor() const { return m_textInfoDimColor; }
QColor ThemeManager::textPurpleColor() const { return m_textPurpleColor; }

// Семантические

QColor ThemeManager::successColor() const { return m_successColor; }
QColor ThemeManager::successLightColor() const { return m_successLightColor; }
QColor ThemeManager::errorColor() const { return m_errorColor; }
QColor ThemeManager::warningColor() const { return m_warningColor; }
QColor ThemeManager::infoColor() const { return m_infoColor; }
QColor ThemeManager::purpleColor() const { return m_purpleColor; }

// Семантическая палитра
QColor ThemeManager::chartColor1() const { return m_chartColor1; }
QColor ThemeManager::chartColor2() const { return m_chartColor2; }
QColor ThemeManager::chartColor3() const { return m_chartColor3; }
QColor ThemeManager::chartColor4() const { return m_chartColor4; }
QColor ThemeManager::chartColor5() const { return m_chartColor5; }

// Служебные

QColor ThemeManager::iconColor() const { return m_iconColor; }
QColor ThemeManager::iconAltColor() const { return m_iconAltColor; }
QColor ThemeManager::overlayColor() const { return m_overlayColor; }

// палитры
QVariantList ThemeManager::chartBarsPalette() const {
    return {QColor("#3f5587"), QColor("#556da3"), QColor("#6781b8"), QColor("#8a9fcc")};
}

QVariantMap ThemeManager::progressGradient() const {
    return {{"start", QColor("#4a8a4a")}, {"end", QColor("#7ab87a")}};
}

QVariantList ThemeManager::chartPalette() const {
    return {m_chartColor1, m_chartColor2, m_chartColor3, m_chartColor4, m_chartColor5};
}

//  Сеттеры
// фон

void ThemeManager::setBackgroundColor(const QColor &color) {
    if (m_backgroundColor == color)
	return;
    m_backgroundColor = color;
    emit backgroundColorChanged();
}

void ThemeManager::setPanelColor(const QColor &color) {
    if (m_panelColor == color)
	return;
    m_panelColor = color;
    emit panelColorChanged();
}

void ThemeManager::setSurfaceColor(const QColor &color) {
    if (m_surfaceColor == color)
	return;
    m_surfaceColor = color;
    emit surfaceColorChanged();
}

void ThemeManager::setSurfaceHoverColor(const QColor &color) {
    if (m_surfaceHoverColor == color)
	return;
    m_surfaceHoverColor = color;
    emit surfaceHoverColorChanged();
}

void ThemeManager::setSurfaceSelectedColor(const QColor &color) {
    if (m_surfaceSelectedColor == color)
	return;
    m_surfaceSelectedColor = color;
    emit surfaceSelectedColorChanged();
}

void ThemeManager::setChartPlotColor(const QColor &color) {
    if (m_chartPlotColor == color)
	return;
    m_chartPlotColor = color;
    emit chartPlotColorChanged();
}
void ThemeManager::setCardColor(const QColor &color) {
    if (m_cardColor == color)
	return;
    m_cardColor = color;
    emit chartPlotColorChanged();
}

// Границы, разделители

void ThemeManager::setBorderColor(const QColor &color) {
    if (m_borderColor == color)
	return;
    m_borderColor = color;
    emit borderColorChanged();
}

void ThemeManager::setDividerColor(const QColor &color) {
    if (m_dividerColor == color)
	return;
    m_dividerColor = color;
    emit dividerColorChanged();
}

void ThemeManager::setChartGridMainColor(const QColor &color) {
    if (m_chartGridMainColor == color)
	return;
    m_chartGridMainColor = color;
    emit chartGridMainColorChanged();
}

void ThemeManager::setChartGridSubColor(const QColor &color) {
    if (m_chartGridSubColor == color)
	return;
    m_chartGridSubColor = color;
    emit chartGridSubColorChanged();
}

// акценты

void ThemeManager::setAccentColor(const QColor &color) {
    if (m_accentColor == color)
	return;
    m_accentColor = color;
    emit accentColorChanged();
}

void ThemeManager::setAccentHoverColor(const QColor &color) {
    if (m_accentHoverColor == color)
	return;
    m_accentHoverColor = color;
    emit accentHoverColorChanged();
}

void ThemeManager::setAccentPressedColor(const QColor &color) {
    if (m_accentPressedColor == color)
	return;
    m_accentPressedColor = color;
    emit accentPressedColorChanged();
}

void ThemeManager::setAccentLightColor(const QColor &color) {
    if (m_accentLightColor == color)
	return;
    m_accentLightColor = color;
    emit accentLightColorChanged();
}
void ThemeManager::setAccentMutedColor(const QColor &color) {
    if (m_accentMutedColor == color)
	return;
    m_accentMutedColor = color;
    emit accentMutedColorChanged();
}

// Текст

void ThemeManager::setTextPrimaryColor(const QColor &color) {
    if (m_textPrimaryColor == color)
	return;
    m_textPrimaryColor = color;
    emit textPrimaryColorChanged();
}

void ThemeManager::setTextSecondaryColor(const QColor &color) {
    if (m_textSecondaryColor == color)
	return;
    m_textSecondaryColor = color;
    emit textSecondaryColorChanged();
}

void ThemeManager::setTextMutedColor(const QColor &color) {
    if (m_textMutedColor == color)
	return;
    m_textMutedColor = color;
    emit textMutedColorChanged();
}

void ThemeManager::setTextFaintColor(const QColor &color) {
    if (m_textFaintColor == color)
	return;
    m_textFaintColor = color;
    emit textFaintColorChanged();
}

void ThemeManager::setTextPlaceholderColor(const QColor &color) {
    if (m_textPlaceholderColor == color)
	return;
    m_textPlaceholderColor = color;
    emit textPlaceholderColorChanged();
}

void ThemeManager::setTextOnAccentColor(const QColor &color) {
    if (m_textOnAccentColor == color)
	return;
    m_textOnAccentColor = color;
    emit textOnAccentColorChanged();
}

// Семантический текст

void ThemeManager::setTextSuccessColor(const QColor &color) {
    if (m_textSuccessColor == color)
	return;
    m_textSuccessColor = color;
    emit textSuccessColorChanged();
}

void ThemeManager::setTextSuccessMutedColor(const QColor &color) {
    if (m_textSuccessMutedColor == color)
	return;
    m_textSuccessMutedColor = color;
    emit textSuccessMutedColorChanged();
}

void ThemeManager::setTextSuccessDimColor(const QColor &color) {
    if (m_textSuccessDimColor == color)
	return;
    m_textSuccessDimColor = color;
    emit textSuccessDimColorChanged();
}

void ThemeManager::setTextErrorColor(const QColor &color) {
    if (m_textErrorColor == color)
	return;
    m_textErrorColor = color;
    emit textErrorColorChanged();
}

void ThemeManager::setTextInfoColor(const QColor &color) {
    if (m_textInfoColor == color)
	return;
    m_textInfoColor = color;
    emit textInfoColorChanged();
}

void ThemeManager::setTextInfoMutedColor(const QColor &color) {
    if (m_textInfoMutedColor == color)
	return;
    m_textInfoMutedColor = color;
    emit textInfoMutedColorChanged();
}

void ThemeManager::setTextInfoDimColor(const QColor &color) {
    if (m_textInfoDimColor == color)
	return;
    m_textInfoDimColor = color;
    emit textInfoDimColorChanged();
}
void ThemeManager::setTextPurpleColor(const QColor &color) {
    if (m_textPurpleColor == color)
	return;
    m_textPurpleColor = color;
    emit textInfoDimColorChanged();
}

// Семантические

void ThemeManager::setSuccessColor(const QColor &color) {
    if (m_successColor == color)
	return;
    m_successColor = color;
    emit successColorChanged();
}

void ThemeManager::setSuccessLightColor(const QColor &color) {
    if (m_successLightColor == color)
	return;
    m_successLightColor = color;
    emit successLightColorChanged();
}

void ThemeManager::setErrorColor(const QColor &color) {
    if (m_errorColor == color)
	return;
    m_errorColor = color;
    emit errorColorChanged();
}

void ThemeManager::setWarningColor(const QColor &color) {
    if (m_warningColor == color)
	return;
    m_warningColor = color;
    emit warningColorChanged();
}

void ThemeManager::setInfoColor(const QColor &color) {
    if (m_infoColor == color)
	return;
    m_infoColor = color;
    emit infoColorChanged();
}

void ThemeManager::setPurpleColor(const QColor &color) {
    if (m_purpleColor == color)
	return;
    m_purpleColor = color;
    emit purpleColorChanged();
}

// Семантическая палитра
void ThemeManager::setChartColor1(const QColor &color) {
    if (m_chartColor1 == color)
	return;
    m_chartColor1 = color;
    emit chartPaletteChanged();
}
void ThemeManager::setChartColor2(const QColor &color) {
    if (m_chartColor2 == color)
	return;
    m_chartColor2 = color;
    emit chartPaletteChanged();
}
void ThemeManager::setChartColor3(const QColor &color) {
    if (m_chartColor3 == color)
	return;
    m_chartColor3 = color;
    emit chartPaletteChanged();
}
void ThemeManager::setChartColor4(const QColor &color) {
    if (m_chartColor4 == color)
	return;
    m_chartColor4 = color;
    emit chartPaletteChanged();
}
void ThemeManager::setChartColor5(const QColor &color) {
    if (m_chartColor5 == color)
	return;
    m_chartColor5 = color;
    emit chartPaletteChanged();
}

// Служебные

void ThemeManager::setIconColor(const QColor &color) {
    if (m_iconColor == color)
	return;
    m_iconColor = color;
    emit iconColorChanged();
}

void ThemeManager::setIconAltColor(const QColor &color) {
    if (m_iconAltColor == color)
	return;
    m_iconAltColor = color;
    emit iconAltColorChanged();
}

void ThemeManager::setOverlayColor(const QColor &color) {
    if (m_overlayColor == color)
	return;
    m_overlayColor = color;
    emit overlayColorChanged();
}