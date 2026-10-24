import QtQuick
import QtQuick.Layouts
import QtGraphs
import QtQuick.Controls
import ApplicantStatsProjectModule

Rectangle {
    id: pagesMenu

    anchors.bottom: statusBar.top
    anchors.bottomMargin: 0
    anchors.left: parent.left
    anchors.margins: 10
    anchors.top: parent.top
    border.color: Colors.borderColor
    border.width: 1
    color: Colors.panelColor
    radius: 12
    width: 48

    ColumnLayout {
        property int innerPadding: 6

        anchors.bottomMargin: innerPadding
        anchors.fill: parent
        anchors.topMargin: innerPadding
        spacing: 8

        PageButton {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: parent.width - (parent.innerPadding * 2)
            Layout.preferredWidth: parent.width - (parent.innerPadding * 2)
            btnIconSource: "qrc:/resources/icons/stats.png"
            btnToolTipName: " Статистика "
            isBtnChecked: (window.currentPageIndex === 0)

            onClicked: {
                window.currentPageIndex = 0;
            }
        }
        PageButton {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: parent.width - (parent.innerPadding * 2)
            Layout.preferredWidth: parent.width - (parent.innerPadding * 2)
            btnIconSource: "qrc:/resources/icons/menu-burger.png"
            btnToolTipName: " Найстройка шаблонов правил приёма "
            isBtnChecked: (window.currentPageIndex === 1)

            onClicked: {
                window.currentPageIndex = 1;
            }
        }
        Item {
            Layout.fillHeight: true
        }
        PageButton {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredHeight: parent.width - (parent.innerPadding * 2)
            Layout.preferredWidth: parent.width - (parent.innerPadding * 2)
            btnIconSource: "qrc:/resources/icons/settings.png"
            btnToolTipName: " Настройки "
            isBtnChecked: (window.currentPageIndex === 2)

            onClicked: {
                window.currentPageIndex = 2;
            }
        }
    }
}