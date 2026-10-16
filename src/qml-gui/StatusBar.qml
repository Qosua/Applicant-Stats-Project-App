import QtQuick
import QtQuick.Layouts
import QtGraphs
import QtQuick.Controls
import ApplicantStatsProjectModule

Rectangle {
    id: statusBar

    anchors.bottom: parent.bottom
    anchors.left: parent.left
    anchors.leftMargin: 15
    anchors.right: parent.right
    anchors.rightMargin: 15
    anchors.topMargin: 5
    color: "#26282b"
    height: 30

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        spacing: 50

        Text {
            id: pathText

            property var arr: qmlHelper.currentTablePath.split("/")

            Layout.preferredWidth: parent.width / 5
            color: "#cccccc"
            elide: Text.ElideMiddle
            font.pointSize: 11
            text: (arr.length && arr[arr.length - 1] !== "" ? "Таблица: " + arr[arr.length - 1] : "Файл не выбран")
        }
        Item {
            Layout.fillWidth: true
        }
        Rectangle {
            Layout.preferredHeight: parent.height
            Layout.preferredWidth: parent.width / 4.6
            color: "transparent"

            RowLayout {
                anchors.fill: parent
                spacing: 15

                Text {
                    Layout.alignment: Qt.AlignVCenter
                    color: "#bbbbbb"
                    font.pointSize: 11
                    text: progressHandler.processName
                    visible: progressHandler.active
                }
                Rectangle {
                    Layout.alignment: Qt.AlignVCenter
                    Layout.fillWidth: true
                    Layout.preferredHeight: parent.height / 3.9
                    color: "#3c3c3c"
                    radius: parent.height / 2
                    visible: progressHandler.active

                    Rectangle {
                        anchors.bottom: parent.bottom
                        anchors.left: parent.left
                        anchors.top: parent.top
                        color: "#5073C1"
                        height: parent.height
                        radius: parent.height
                        width: parent.width * progressHandler.progress
                    }
                }
                Text {
                    Layout.alignment: Qt.AlignVCenter
                    color: "#bbbbbb"
                    font.pointSize: 11
                    text: progressHandler.processMessage
                    visible: progressHandler.active
                }
            }
        }
        Item {
            Layout.fillWidth: true
        }
        Text {
            Layout.preferredWidth: parent.width / 5
            color: "#cccccc"
            font.pointSize: 11
            horizontalAlignment: Text.AlignRight
            text: "Версия: " + qmlHelper.appVersion
        }
    }
}

