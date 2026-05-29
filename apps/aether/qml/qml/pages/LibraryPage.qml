import QtQuick 2.15
import "../themes"
import "../components"

Item {
    AnimatedBackground {
        anchors.fill: parent
    }

    GlassPanel {
        anchors.fill: parent
        anchors.margins: Theme.margin
        glowColor: Theme.accentPurple

        Column {
            anchors.fill: parent
            spacing: Theme.margin

            Text {
                text: "Media Library"
                font: Theme.fontHeader
                color: Theme.textPrimary
            }

            ListView {
                width: parent.width
                height: parent.height - 60
                clip: true
                spacing: 8
                model: 20

                delegate: Rectangle {
                    width: ListView.view.width
                    height: 48
                    radius: Theme.radiusSmall
                    color: index % 2 === 0 ? Qt.rgba(1, 1, 1, 0.03) : "transparent"

                    Row {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.margins: 12
                        spacing: 12

                        Text {
                            text: "Track " + (index + 1)
                            font: Theme.fontBody
                            color: Theme.textPrimary
                        }

                        Text {
                            text: "Artist Name"
                            font: Theme.fontCaption
                            color: Theme.textSecondary
                        }
                    }
                }
            }
        }
    }
}
