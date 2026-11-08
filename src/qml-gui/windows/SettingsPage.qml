import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import ApplicantStatsProjectModule

Rectangle {
    id: settingsPage

    color: Colors.panelColor

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 24
        spacing: 16

        Label {
            color: Colors.textPrimaryColor
            font.bold: true
            font.pixelSize: 24
            text: "Настройки"
        }
        Button {
            id: buttonTheme

            Layout.preferredHeight: 42
            Layout.preferredWidth: 220
            text: Colors.isLightTheme ? "Включить тёмную тему" : "Включить светлую тему"

            background: Rectangle {
                border.color: Colors.borderColor
                color: parent.hovered ? Colors.surfaceHoverColor : Colors.surfaceLightColor   // или Colors.surfaceColor / Colors.cardColor
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
                text: parent.text
                verticalAlignment: Text.AlignVCenter
            }

            onClicked: Colors.setLightTheme(!Colors.isLightTheme)
        }
        Item {
            Layout.fillHeight: true
        }
    }
}