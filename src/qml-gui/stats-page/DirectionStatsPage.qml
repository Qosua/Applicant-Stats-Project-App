import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import ApplicantStatsProjectModule

Item {
    id: page

    property var payload: null
    property int sourceIndex: payload ? (payload.sourceIndex ?? -1) : -1
    property var stats: null

    function reloadStats() {
        stats = (sourceIndex >= 0) ? statsPageModel.directionStatsAt(sourceIndex) : null;
    }

    Component.onCompleted: reloadStats()
    onSourceIndexChanged: reloadStats()

    Connections {
        function onLoadDirectionPage(index) {
            page.reloadStats();
        }

        target: statsPageModel
    }
    ScrollView {
        id: scrollView
        anchors.fill: parent
        anchors.margins: 16
        clip: true
        contentWidth: availableWidth

        ColumnLayout {
            width: page.width - 32
            spacing: 12

            //page header
            Label {
                color: Colors.textPrimaryColor
                font.pixelSize: 24
                font.weight: Font.Medium
                text: stats ? stats.name : "STATS ARE NULL"
            }
            RowLayout {
                spacing: 4

                Label {
                    color: Colors.textMutedColor
                    font.pixelSize: 16
                    font.weight: Font.Medium
                    text: "Факультет:"
                }
                Label {
                    Layout.fillWidth: true
                    color: Colors.textPrimaryColor
                    elide: Text.ElideRight
                    font.pixelSize: 16
                    font.weight: Font.Medium
                    text: stats ? stats.facultyName : "STATS ARE NULL"
                }
            }

            //page header
            RowLayout {
                spacing: 12

                Label {
                    color: Colors.textSecondaryColor
                    font.pixelSize: 15
                    font.weight: Font.Medium
                    text: "Вид обучения:"
                }
                Label {
                    color: Colors.textSuccessMutedColor
                    font.pixelSize: 15
                    font.weight: Font.Medium
                    text: (stats ? stats.studyType : "ОШИБКА ВИДА ОБУЧЕНИЯ (QML)")
                }
                Item {
                }
                Label {
                    color: Colors.textSecondaryColor
                    font.pixelSize: 15
                    font.weight: Font.Medium
                    text: "Форма обучения:"
                }
                Label {
                    color: Colors.textInfoMutedColor
                    font.pixelSize: 15
                    font.weight: Font.Medium
                    text: (stats ? stats.studyForm : "ОШИБКА ФОРМЫ ОБУЧЕНИЯ (QML)")
                }
                Item {
                }
                Label {
                    color: Colors.textSecondaryColor
                    font.pixelSize: 15
                    font.weight: Font.Medium
                    text: "Код направления:"
                }
                Label {
                    color: Colors.textPurpleColor
                    font.pixelSize: 15
                    font.weight: Font.Medium
                    text: (stats ? stats.code : "ОШИБКА КОДА НАПРАВЛЕНИЯ (QML)")
                }
            }

            //page header divider
            Rectangle {
                Layout.fillWidth: true
                color: Colors.dividerColor
                height: 1
            }

            //score graph and applicants list
            SplitView {
                Layout.fillWidth: true
                Layout.preferredHeight: (scrollView.height / 2) + 40
                anchors.margins: 2
                spacing: 4

                handle: Rectangle {
                    color: SplitHandle.hovered ? Colors.accentColor : "transparent"
                    implicitWidth: 6

                    Behavior on color {
                        ColorAnimation {
                            duration: 100
                        }
                    }
                }

                //score graph
                ScoreDist {
                    SplitView.minimumWidth: parent.width / 2.4
                    SplitView.preferredHeight: parent.height
                    SplitView.preferredWidth: parent.width / 2.3
                    bucketStep: stats ? stats.scoreBucketStep : 10
                    distribution: stats ? stats.scoreDistribution : []
                    firstBucketScore: stats ? stats.scoreBucketStart : 100
                }

                //applicants list
                Item {
                    id: applicantsList

                    property bool isFIOHidden: false
                    property bool isIDHidden: false
                    property bool isPhoneHidden: false
                    property bool isScoreHidden: false

                    SplitView.minimumWidth: parent.width / 4

                    //header
                    Row {
                        id: listHeader

                        anchors.leftMargin: 20
                        anchors.top: parent.top
                        height: 45
                        leftPadding: 20
                        spacing: 6
                        width: parent.width

                        Label {
                            color: Colors.textFaintColor
                            font.family: "Consolas"
                            font.pixelSize: 15
                            text: "#"
                            width: 25
                        }
                        ColumnLayout {
                            spacing: 2
                            width: 77

                            Label {
                                color: Colors.textInfoDimColor
                                font.family: "Consolas"
                                font.pixelSize: 15
                                text: "ID"
                            }
                            CustomCheckBox {
                                onIsToggledChanged: {
                                    applicantsList.isIDHidden = !applicantsList.isIDHidden;
                                }
                            }
                        }
                        ColumnLayout {
                            spacing: 2
                            width: 77

                            Label {
                                color: Colors.textSuccessDimColor
                                font.family: "Consolas"
                                font.pixelSize: 15
                                text: "Баллы"
                            }
                            CustomCheckBox {
                                onIsToggledChanged: {
                                    applicantsList.isScoreHidden = !applicantsList.isScoreHidden;
                                }
                            }
                        }
                        ColumnLayout {
                            spacing: 2
                            width: 140

                            Label {
                                color: Colors.textFaintColor
                                font.family: "Consolas"
                                font.pixelSize: 15
                                text: "Телефон"
                            }
                            CustomCheckBox {
                                onIsToggledChanged: {
                                    applicantsList.isPhoneHidden = !applicantsList.isPhoneHidden;
                                }
                            }
                        }
                        ColumnLayout {
                            spacing: 2

                            Label {
                                color: Colors.textMutedColor
                                font.family: "Consolas"
                                font.pixelSize: 15
                                text: "ФИО"
                            }
                            CustomCheckBox {
                                onIsToggledChanged: {
                                    applicantsList.isFIOHidden = !applicantsList.isFIOHidden;
                                }
                            }
                        }
                    }

                    //graph divider
                    Rectangle {
                        id: headerDivider

                        anchors.top: listHeader.bottom
                        color: Colors.borderColor
                        height: 1
                        width: parent.width
                    }

                    //list
                    ListView {
                        id: applicantListView

                        anchors.bottom: parent.bottom
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.top: headerDivider.bottom
                        anchors.topMargin: 4
                        clip: true
                        model: applicantsListModel
                        spacing: 1

                        delegate: Rectangle {
                            id: applicantDelegate

                            required property string applicantEmail
                            required property int applicantId
                            required property string applicantName
                            required property string applicantPhone
                            required property string applicantScore
                            required property int index

                            color: hoverHandler.hovered ? Colors.surfaceHoverColor : Colors.surfaceColor
                            height: 24
                            radius: 4
                            width: ListView.view.width

                            Behavior on color {
                                ColorAnimation {
                                    duration: 100
                                }
                            }

                            HoverHandler {
                                id: hoverHandler

                            }
                            RowLayout {
                                anchors.fill: parent
                                anchors.leftMargin: 20
                                anchors.rightMargin: 20
                                spacing: 6

                                Label {
                                    Layout.preferredWidth: 25
                                    color: Colors.textFaintColor
                                    font.family: "Consolas"
                                    font.pixelSize: 12
                                    horizontalAlignment: Text.AlignLeft
                                    text: applicantDelegate.index + 1
                                }
                                Label {
                                    Layout.preferredWidth: 77
                                    color: Colors.textInfoColor
                                    font.family: "Consolas"
                                    font.pixelSize: 12
                                    text: (applicantsList.isIDHidden ? "..." : applicantDelegate.applicantId)
                                }
                                Label {
                                    Layout.preferredWidth: 77
                                    color: Colors.textSuccessColor
                                    elide: Text.ElideRight
                                    font.family: "Consolas"
                                    font.pixelSize: 12
                                    text: (applicantsList.isScoreHidden ? "..." : applicantDelegate.applicantScore)
                                }
                                Label {
                                    Layout.preferredWidth: 140
                                    color: Colors.textMutedColor
                                    font.family: "Consolas"
                                    font.pixelSize: 12
                                    text: (applicantsList.isPhoneHidden ? "..." : applicantDelegate.applicantPhone)
                                }
                                Label {
                                    Layout.fillWidth: true
                                    Layout.preferredWidth: 1
                                    color: Colors.textPrimaryColor
                                    elide: Text.ElideRight
                                    font.family: "Consolas"
                                    font.pixelSize: 12
                                    text: (applicantsList.isFIOHidden ? "..." : applicantDelegate.applicantName)
                                }
                            }
                        }

                        NumberAnimation {
                            id: scrollAnim

                            duration: 180
                            easing.type: Easing.OutQuad
                            property: "contentY"
                            target: applicantListView
                        }
                        WheelHandler {
                            onWheel: event => {
                                const delta = event.angleDelta.y * 0.54;
                                const animY = scrollAnim.running ? scrollAnim.to : applicantListView.contentY;

                                scrollAnim.to = Math.max(0, Math.min(animY - delta, applicantListView.contentHeight - applicantListView.height));
                                scrollAnim.restart();
                            }
                        }
                    }
                }
            }

            //divider2
            Rectangle {
                id: divider2

                Layout.fillWidth: true
                color: Colors.dividerColor
                height: 1
            }

            //progressBar and panels
            ColumnLayout {
                Layout.fillWidth: true
                spacing: 10

                //progressBar
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 78
                    border.color: Colors.borderColor
                    border.width: 1
                    color: Colors.cardColor
                    radius: 8

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 14
                        spacing: 10

                        RowLayout {
                            spacing: 10

                            Label {
                                Layout.fillWidth: true
                                color: Colors.textSecondaryColor
                                font.pixelSize: 11
                                font.weight: Font.DemiBold
                                text: "ЗАЧИСЛЕНО"
                            }
                            Label {
                                color: Colors.textPrimaryColor
                                font.pixelSize: 18
                                font.weight: Font.DemiBold
                                text: (stats ? stats.size : 0) + " / " + (stats ? stats.capacity : 0)
                            }
                            Label {
                                color: Colors.successColor
                                font.pixelSize: 18
                                font.weight: Font.Medium
                                text: stats && stats.capacity > 0 ? Math.round((stats.size / stats.capacity) * 100) + "%" : "0%"
                            }
                        }
                        Rectangle {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 6
                            color: Colors.surfaceColor
                            radius: 3

                            Rectangle {
                                height: parent.height
                                radius: parent.radius
                                width: parent.width * (stats && stats.capacity > 0 ? Math.min(stats.size / stats.capacity, 1) : 0)

                                gradient: Gradient {
                                    orientation: Gradient.Horizontal

                                    GradientStop {
                                        color: Colors.progressGradientStart
                                        position: 0.0
                                    }
                                    GradientStop {
                                        color: Colors.progressGradientEnd
                                        position: 1.0
                                    }
                                }
                                Behavior on width {
                                    NumberAnimation {
                                        duration: 350
                                        easing.type: Easing.OutCubic
                                    }
                                }
                            }
                        }
                    }
                }

                //panels
                RowLayout {
                    Layout.fillWidth: true
                    spacing: 10

                    StatCard {
                        accentColor: Colors.statisticsPassingColor
                        label: "ПРОХОДНОЙ"
                        value: stats && stats.size === stats.capacity ? stats.minScore : "-"
                    }
                    StatCard {
                        accentColor: Colors.statisticsMaximumColor
                        label: "МАКСИМУМ"
                        value: stats && stats.maxScore !== undefined ? stats.maxScore : "-"
                    }
                    StatCard {
                        accentColor: Colors.statisticsMinimumColor
                        label: "МИНИМУМ"
                        value: stats && stats.minScore !== undefined ? stats.minScore : "-"
                    }
                    StatCard {
                        accentColor: Colors.statisticsAverageColor
                        label: "СРЕДНИЙ"
                        value: stats && stats.meanScore !== undefined ? stats.meanScore.toFixed(1) : "-"
                    }
                    StatCard {
                        accentColor: Colors.statisticsMedianColor
                        label: "МЕДИАНА"
                        value: stats && stats.midScore !== undefined ? stats.midScore.toFixed(1) : "-"
                    }
                }
            }

        }
    }

    component CustomCheckBox: Rectangle {
        id: checkBox

        property bool isToggled: false

        color: "transparent"
        height: childrenRect.height
        width: childrenRect.width

        Row {
            spacing: 3

            // Checkbox icons
            Text {
                id: innerText

                color: Colors.textFaintColor
                font.family: "Lato"
                font.pixelSize: 17
                text: checkBox.isToggled ? "\uf046" : "\uf096"
                width: 16
            }
            // Checkbox text
            Text {
                anchors.verticalCenter: innerText.verticalCenter
                color: Colors.textMutedColor
                font.family: "Lato"
                font.pixelSize: 13
                text: isToggled ? "Скрыто" : "Скрыть"
            }
        }
        MouseArea {
            anchors.fill: parent

            onClicked: {
                checkBox.isToggled = !checkBox.isToggled;
            }
        }
    }

    //panel component
    component StatCard: Rectangle {
        property color accentColor: Colors.textMutedColor
        property string label: ""
        property var value: "—"

        Layout.fillWidth: true
        Layout.preferredHeight: 78
        border.color: Colors.borderColor
        border.width: 1
        color: Colors.cardColor
        radius: 8

        // Цветной акцент слева
        Rectangle {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 1
            anchors.top: parent.top
            color: accentColor
            opacity: 0.85
            radius: 2
            width: 3
        }
        ColumnLayout {
            anchors.fill: parent
            anchors.leftMargin: 18
            anchors.margins: 14
            spacing: 4

            Label {
                color: Colors.textSecondaryColor
                font.pixelSize: 11
                font.weight: Font.DemiBold
                text: label
            }
            Item {
                Layout.fillHeight: true
            }
            Label {
                color: accentColor
                font.pixelSize: 26
                font.weight: Font.DemiBold
                text: value
            }
        }
    }
}