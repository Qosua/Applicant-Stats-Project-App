import QtQuick
import QtQuick.Controls
import ApplicantStatsProjectModule

ComboBox {
    id: comboBox

    property var comboBoxModel: []
    property var entryCommisionInfoToSend: []

    model: comboBoxModel
    valueRole: "entryCommisionNameYearIsBachelor"
    currentIndex: 0

    contentItem: Text {
        text: comboBox.currentValue ?
            comboBox.currentValue[0] + "-"
            + (comboBox.currentValue[1] ? "Бакалавры" : "Магистры") + "-"
            + comboBox.currentValue[2]
            : ""

        leftPadding: 8
        color: Colors.textSecondaryColor
        font.pixelSize: 14
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        radius: 8
        color: comboBox.hovered ? Colors.surfaceHoverColor : Colors.surfaceColor
        border.color: (comboBox.popup.visible || comboBox.hovered) ? Colors.accentColor : Colors.borderColor
        border.width: 1

        Behavior on color {
            ColorAnimation { duration: 100 }
        }
    }

    indicator: Text {
        x: comboBox.width - width - 10
        y: comboBox.topPadding + (comboBox.availableHeight - height) / 2
        text: comboBox.popup.visible ? "⯅" : "⯆"
        color: Colors.accentMutedColor
        font.pixelSize: 12
    }

    delegate: ItemDelegate {
        width: comboBox.width
        height: 30

        contentItem: Text {
            text: (model.entryCommisionName
                + "-"
                + (model.entryCommisionIsBachelor ? "Бакалавры" : "Магистры")
                + "-"
                + model.entryCommisionYear)
            color: Colors.textSecondaryColor
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter
            leftPadding: 12
            elide: Text.ElideRight
        }

        background: Rectangle {
            color: highlighted ?Colors.surfaceSelectedColor : hovered ? Colors.surfaceHoverColor : Colors.panelColor
            Behavior on color {
                ColorAnimation { duration: 100 }
            }
        }

        highlighted: comboBox.highlightedIndex === index

        HoverHandler {
            cursorShape: Qt.PointingHandCursor
        }
    }

    popup: Popup {
        y: comboBox.height + 4
        width: comboBox.width
        implicitHeight: contentItem.implicitHeight + 8
        padding: 4

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: comboBox.popup.visible ? comboBox.delegateModel : null
            currentIndex: comboBox.highlightedIndex
        }

        background: Rectangle {
            color: Colors.panelColor
            border.color: Colors.borderColor
            border.width: 1
            radius: 8
        }
    }
}