import QtQuick
import QtQuick.Layouts
import QtGraphs
import QtQuick.Controls
import ApplicantStatsProjectModule

Window {
    id: window

    property int currentPageIndex: 0

    width: 1280; minimumWidth: 720
    height: 720; minimumHeight: 480

    visible: true
    color: Colors.backgroundColor

    LeftTopGradient {
        anchors.fill: parent
    }

    PagesMenu {
        id: pagesMenu
    }

    StackLayout {
        id: pagesStack

        anchors.top: parent.top
        anchors.bottom: statusBar.top
        anchors.right: parent.right
        anchors.left: pagesMenu.right

        anchors.margins: 8
        anchors.topMargin: 10
        anchors.bottomMargin: 0

        currentIndex: window.currentPageIndex

        StatsPage {
            id: splitView
        }

        Rectangle {
            color: "#232b40" //заглушка пока без изменения
        }

        Rectangle {
            color: "#7160a8" //заглушка пока без изменения

        }
    }

    StatusBar {
        id: statusBar
    }

    Rectangle {
        id: dimOverlay
        anchors.fill: parent
        color: Colors.overlayColor
        opacity: 0.45
        visible: windowManager.isMainWindowShadowed
        Behavior on opacity {
            NumberAnimation { duration: 150; easing.type: Easing.OutQuad }
        }
    }

}



