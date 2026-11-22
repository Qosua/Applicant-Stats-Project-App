import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import ApplicantStatsProjectModule

Item {
    id: settingsPage

    // Индекс выбранного раздела: 0 - настройки приложения, 1 - настройки цветовой темы
    property int currentSection: 0

    // Кнопка меню в левой панели
    component MenuButton: Button {
        id: menuBtn

        property bool isChecked: false
        property string subtitle: ""

        Layout.fillWidth: true
        implicitHeight: 56
        flat: true
        hoverEnabled: true

        contentItem: Item {
            Column {
                anchors.left: parent.left
                anchors.leftMargin: 18
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                spacing: 2

                Text {
                    width: parent.width
                    text: menuBtn.text
                    color: Colors.textPrimaryColor
                    font.pixelSize: 15
                    font.weight: menuBtn.isChecked ? Font.DemiBold : Font.Normal
                    elide: Text.ElideRight
                }
                Text {
                    width: parent.width
                    text: menuBtn.subtitle
                    color: menuBtn.isChecked ? Colors.textSecondaryColor : Colors.textMutedColor
                    font.pixelSize: 12
                    elide: Text.ElideRight
                    visible: text !== ""
                }
            }
        }

        background: Rectangle {
            radius: 8
            color: menuBtn.isChecked ? Colors.surfaceSelectedColor
                : menuBtn.hovered   ? Colors.surfaceHoverColor
                    : "transparent"
            border.width: 1
            border.color: menuBtn.isChecked ? Colors.accentColor : "transparent"

            Behavior on color {
                ColorAnimation {
                    duration: 100
                }
            }
            Behavior on border.color {
                ColorAnimation {
                    duration: 100
                }
            }

            // Акцентная полоска слева у выбранного пункта
            Rectangle {
                anchors.left: parent.left
                anchors.leftMargin: 6
                anchors.verticalCenter: parent.verticalCenter
                width: 3
                height: menuBtn.isChecked ? parent.height - 20 : 0
                radius: 2
                color: Colors.accentColor

                Behavior on height {
                    NumberAnimation {
                        duration: 120
                        easing.type: Easing.OutQuad
                    }
                }
            }
        }

        HoverHandler {
            cursorShape: Qt.PointingHandCursor
        }
    }

    // Заголовок раздела в правой панели
    component SectionTitle: Label {
        color: Colors.textPrimaryColor
        font.bold: true
        font.pixelSize: 24
    }

    // Строка настройки: подпись слева, элемент управления справа
    component SettingRow: RowLayout {
        property string label: ""

        Layout.fillWidth: true
        spacing: 16

        Label {
            Layout.alignment: Qt.AlignVCenter
            Layout.preferredWidth: 150
            color: Colors.textSecondaryColor
            font.pixelSize: 16
            text: parent.label
        }
    }

    SplitView {
        anchors.fill: parent
        orientation: Qt.Horizontal

        // Ручка изменения размера - как на странице статистики
        handle: Rectangle {
            implicitWidth: 4
            color: SplitHandle.hovered || SplitHandle.pressed ? Colors.accentColor : "transparent"

            Behavior on color {
                ColorAnimation {
                    duration: 100
                }
            }
        }

        // ---------- Левая панель: список разделов ----------
        Rectangle {
            SplitView.preferredWidth: parent.width / 4
            SplitView.minimumWidth: 200
            SplitView.maximumWidth: parent.width / 2

            color: Colors.panelColor
            border.color: Colors.borderColor
            border.width: 1
            topLeftRadius: 10
            bottomLeftRadius: 10

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 8
                spacing: 4

                MenuButton {
                    text: "Настройки приложения"
                    subtitle: "Общие параметры программы"
                    isChecked: settingsPage.currentSection === 0
                    onClicked: settingsPage.currentSection = 0
                }
                MenuButton {
                    text: "Настройки цветовой темы"
                    subtitle: "Светлая и тёмная тема"
                    isChecked: settingsPage.currentSection === 1
                    onClicked: settingsPage.currentSection = 1
                }
                Item {
                    Layout.fillHeight: true
                }
            }
        }

        // ---------- Правая панель: содержимое раздела (~3/4) ----------
        Rectangle {
            SplitView.fillWidth: true
            SplitView.minimumWidth: 300

            color: Colors.panelColor
            border.color: Colors.borderColor
            border.width: 1
            topRightRadius: 10
            bottomRightRadius: 10
            clip: true

            StackLayout {
                anchors.fill: parent
                anchors.margins: 24
                currentIndex: settingsPage.currentSection

                // --- Настройки приложения ---
                ColumnLayout {
                    spacing: 16

                    SectionTitle {
                        text: "Настройки приложения"
                    }
                    Label {
                        color: Colors.textMutedColor
                        font.pixelSize: 15
                        text: "Здесь пока нет настроек"
                    }
                    Item {
                        Layout.fillHeight: true
                    }
                }

                // --- Настройки цветовой темы ---
                ColumnLayout {
                    spacing: 16

                    SectionTitle {
                        text: "Настройки цветовой темы"
                    }

                    SettingRow {
                        label: "Тема оформления"

                        Button {
                            id: buttonTheme

                            Layout.preferredHeight: 42
                            Layout.preferredWidth: 220
                            hoverEnabled: true
                            text: Colors.isLightTheme ? "Включить тёмную тему" : "Включить светлую тему"

                            background: Rectangle {
                                border.color: Colors.borderColor
                                color: buttonTheme.hovered ? Colors.surfaceHoverColor : Colors.surfaceLightColor
                                radius: 8

                                Behavior on color {
                                    ColorAnimation {
                                        duration: 100
                                    }
                                }
                            }
                            contentItem: Text {
                                color: Colors.textPrimaryColor
                                font.pixelSize: 15
                                horizontalAlignment: Text.AlignHCenter
                                text: buttonTheme.text
                                verticalAlignment: Text.AlignVCenter
                            }

                            HoverHandler {
                                cursorShape: Qt.PointingHandCursor
                            }

                            onClicked: Colors.setLightTheme(!Colors.isLightTheme)
                        }
                        Item {
                            Layout.fillWidth: true
                        }
                    }

                    Item {
                        Layout.fillHeight: true
                    }
                }
            }
        }
    }
}
