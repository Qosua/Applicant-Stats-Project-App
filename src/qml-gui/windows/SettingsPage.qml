import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import ApplicantStatsProjectModule

Rectangle {
    id: settingsPage

    color: Colors.backgroundColor

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
            Layout.preferredHeight: 42
            Layout.preferredWidth: 220
            text: Colors.isLightTheme ? "Включить тёмную тему" : "Включить светлую тему"

            onClicked: {
                Colors.setLightTheme(!Colors.isLightTheme);
            }
        }
        Item {
            Layout.fillHeight: true
        }
    }
}