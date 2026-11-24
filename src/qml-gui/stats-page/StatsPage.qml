import QtQuick
import QtQuick.Layouts
import QtGraphs
import QtQuick.Controls
import ApplicantStatsProjectModule

SplitView {
    function getFileName(mode) {
        if (mode === "faculty") {
            return "FacultyStatsPage.qml";
        } else if (mode === "direction") {
            return "DirectionStatsPage.qml";
        } else {
            return "EmptyStatsPlaceholder.qml";
        }
    }

    orientation: Qt.Horizontal

    handle: Rectangle {
        color: SplitHandle.hovered ? Colors.accentColor : "transparent"
        implicitWidth: 4

        Behavior on color {
            ColorAnimation {
                duration: 100
            }
        }
    }

    Rectangle {
        SplitView.minimumWidth: parent.width / 10
        SplitView.preferredWidth: parent.width / 4
        bottomLeftRadius: 10
        color: "transparent"
        topLeftRadius: 10

        SplitView {
            anchors.fill: parent
            orientation: Qt.Vertical

            handle: Rectangle {
                color: SplitHandle.hovered ? Colors.accentColor : "transparent"
                implicitHeight: 5

                Behavior on color {
                    ColorAnimation {
                        duration: 100
                    }
                }
            }

            Rectangle {
                SplitView.fillHeight: tablesList.collapsed
                SplitView.minimumHeight: parent.height / 10
                SplitView.preferredHeight: parent.height / 2
                border.color: Colors.borderColor
                border.width: 1
                color: Colors.panelColor
                topLeftRadius: 10

                FacultyTreeView {
                    anchors.fill: parent
                    anchors.margins: 8

                    onDirectionSelected: idx => {
                        detailLoader.mode = "direction";
                        detailLoader.payload = {
                            sourceIndex: idx
                        };
                    }
                    onFacultySelected: name => {
                        detailLoader.mode = "faculty";
                        detailLoader.payload = {
                            facultyName: name
                        };
                    }
                    onSelectionCleared: {
                        detailLoader.mode = "none";
                        detailLoader.payload = null;
                    }
                }
            }
            TablesList {
                id: tablesList

                SplitView.maximumHeight: collapsed ? collapsedHeight : Number.POSITIVE_INFINITY
                SplitView.minimumHeight: collapsed ? collapsedHeight : parent.height / 10
                SplitView.preferredHeight: collapsed ? collapsedHeight : parent.height / 2
                border.color: tablesList.dropped ? Colors.accentColor : Colors.borderColor
                border.width: 1
                bottomLeftRadius: 10
                color: Colors.panelColor
            }
        }
    }
    Rectangle {
        SplitView.minimumWidth: parent.width / 10
        SplitView.preferredWidth: parent.width / (3 / 4)
        border.color: Colors.borderColor
        border.width: 1
        bottomRightRadius: 10
        clip: true
        color: Colors.panelColor
        topRightRadius: 10

        Rectangle {
            id: searchBar

            anchors.left: parent.left
            anchors.margins: 5
            anchors.right: parent.right
            anchors.top: parent.top
            height: visible ? 40 : 0
            visible: false
        }
        Loader {
            id: detailLoader

            property string mode: "none"
            property var payload: null

            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 1
            anchors.right: parent.right
            anchors.top: searchBar.bottom
            source: getFileName(mode)

            onLoaded: if (item)
                item.payload = payload
            onPayloadChanged: if (item)
                item.payload = payload

            Connections {
                function onLoadDirectionPage(index) {
                    detailLoader.mode = "direction";
                    detailLoader.payload = {
                        sourceIndex: index
                    };
                }
                function onLoadFacultyPage(name) {
                    detailLoader.mode = "faculty";
                    detailLoader.payload = {
                        facultyName: name
                    };
                }
                function onNothingToLoad() {
                    detailLoader.mode = "none";
                    detailLoader.payload = null;
                }

                target: statsPageModel
            }
        }
    }
}