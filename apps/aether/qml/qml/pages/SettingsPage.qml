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
        glowColor: Theme.accentCyan

        Column {
            anchors.fill: parent
            spacing: Theme.margin

            Text {
                text: "System Settings"
                font: Theme.fontHeader
                color: Theme.textPrimary
            }

            Repeater {
                model: ["Dark Mode", "Enable Notifications", "High Quality Audio", "Network Proxy"]

                delegate: Rectangle {
                    width: parent.width
                    height: 48
                    radius: Theme.radiusSmall
                    color: Qt.rgba(1, 1, 1, 0.03)

                    Row {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.margins: 12

                        Text {
                            text: modelData
                            font: Theme.fontBody
                            color: Theme.textPrimary
                        }

                        Item {
                            width: 40
                            height: 24
                        }
                    }
                }
            }
        }
    }
}
