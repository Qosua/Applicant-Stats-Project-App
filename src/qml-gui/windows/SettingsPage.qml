import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import ApplicantStatsProjectModule

Item {
    id: settingsPage

    // Индекс выбранного раздела: 0 - настройки приложения, 1 - настройки цветовой темы
    property int currentSection: 0

    SplitView {
        anchors.fill: parent
        orientation: Qt.Horizontal

        // Ручка изменения размера - как на странице статистики
        handle: Rectangle {
            color: SplitHandle.hovered || SplitHandle.pressed ? Colors.accentColor : "transparent"
            implicitWidth: 4

            Behavior on color {
                ColorAnimation {
                    duration: 100
                }
            }
        }

        // ---------- Левая панель: список разделов ----------
        Rectangle {
            SplitView.maximumWidth: parent.width / 2
            SplitView.minimumWidth: 200
            SplitView.preferredWidth: parent.width / 4
            border.color: Colors.borderColor
            border.width: 1
            bottomLeftRadius: 10
            color: Colors.panelColor
            topLeftRadius: 10

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 8
                spacing: 4

                MenuButton {
                    isChecked: settingsPage.currentSection === 0
                    subtitle: "Общие параметры программы"
                    text: "Настройки приложения"

                    onClicked: settingsPage.currentSection = 0
                }
                MenuButton {
                    isChecked: settingsPage.currentSection === 1
                    subtitle: "Светлая и тёмная тема"
                    text: "Настройки цветовой темы"

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
            border.color: Colors.borderColor
            border.width: 1
            bottomRightRadius: 10
            clip: true
            color: Colors.panelColor
            topRightRadius: 10

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

                        ComboBox {
                            id: themeSelector

                            Layout.preferredHeight: 42
                            Layout.preferredWidth: 220
                            currentIndex: Colors.currentTheme
                            model: ["Dark", "Light", "CLion Light"]

                            // Сам ComboBox
                            background: Rectangle {
                                border.color: Colors.borderColor
                                color: themeSelector.hovered ? Colors.surfaceHoverColor : Colors.surfaceLightColor
                                radius: 8
                            }
                            contentItem: Text {
                                color: Colors.textPrimaryColor
                                elide: Text.ElideRight
                                font.pixelSize: 15
                                leftPadding: 8
                                rightPadding: 30
                                text: themeSelector.displayText
                                verticalAlignment: Text.AlignVCenter
                            }

                            indicator: Text {
                                x: themeSelector.width - width - 12
                                y: (themeSelector.height - height) / 2
                                text: "▼"
                                color: Colors.textSecondaryColor
                                font.pixelSize: 12
                            }

                            // Элементы списка
                            delegate: ItemDelegate {
                                height: 36
                                highlighted: themeSelector.highlightedIndex === index
                                width: themeSelector.width

                                background: Rectangle {
                                    color: parent.highlighted ? Colors.surfaceSelectedColor : parent.hovered ? Colors.surfaceHoverColor : "transparent"
                                    radius: 5
                                }
                                contentItem: Text {
                                    color: Colors.textPrimaryColor
                                    leftPadding: 8
                                    text: modelData
                                    verticalAlignment: Text.AlignVCenter
                                }
                            }

                            // Выпадающий список
                            popup: Popup {
                                padding: 4
                                width: themeSelector.width
                                y: themeSelector.height

                                background: Rectangle {
                                    border.color: Colors.borderColor
                                    color: Colors.panelColor
                                    radius: 8
                                }
                                contentItem: ListView {
                                    clip: true
                                    currentIndex: themeSelector.highlightedIndex
                                    implicitHeight: contentHeight
                                    model: themeSelector.popup.visible ? themeSelector.delegateModel : null
                                }
                            }

                            onActivated: function (index) {
                                Colors.setCurrentTheme(index);
                            }
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

    // Кнопка меню в левой панели
    component MenuButton: Button {
        id: menuBtn

        property bool isChecked: false
        property string subtitle: ""

        Layout.fillWidth: true
        flat: true
        hoverEnabled: true
        implicitHeight: 56

        background: Rectangle {
            border.color: menuBtn.isChecked ? Colors.accentColor : "transparent"
            border.width: 1
            color: menuBtn.isChecked ? Colors.surfaceSelectedColor : menuBtn.hovered ? Colors.surfaceHoverColor : "transparent"
            radius: 8

            Behavior on color {
                ColorAnimation {
                    duration: 100
                }
            }

            // Акцентная полоска слева у выбранного пункта
            Rectangle {
                anchors.left: parent.left
                anchors.leftMargin: 6
                anchors.verticalCenter: parent.verticalCenter
                color: Colors.accentColor
                height: menuBtn.isChecked ? parent.height - 20 : 0
                radius: 2
                width: 3

                Behavior on height {
                    NumberAnimation {
                        duration: 120
                        easing.type: Easing.OutQuad
                    }
                }
            }
        }
        contentItem: Item {
            Column {
                anchors.left: parent.left
                anchors.leftMargin: 18
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                spacing: 2

                Text {
                    color: Colors.textPrimaryColor
                    elide: Text.ElideRight
                    font.pixelSize: 15
                    font.weight: menuBtn.isChecked ? Font.DemiBold : Font.Normal
                    text: menuBtn.text
                    width: parent.width
                }
                Text {
                    color: menuBtn.isChecked ? Colors.textSecondaryColor : Colors.textMutedColor
                    elide: Text.ElideRight
                    font.pixelSize: 12
                    text: menuBtn.subtitle
                    visible: text !== ""
                    width: parent.width
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
}
