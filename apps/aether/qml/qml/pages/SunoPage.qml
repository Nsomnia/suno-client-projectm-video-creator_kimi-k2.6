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
        glowColor: Theme.accentMagenta

        Column {
            anchors.fill: parent
            spacing: Theme.margin

            Text {
                text: "Suno Integration"
                font: Theme.fontHeader
                color: Theme.textPrimary
            }

            Rectangle {
                width: parent.width
                height: 40
                radius: Theme.radiusSmall
                color: Theme.bgSurface
                border.color: Qt.rgba(1, 1, 1, 0.1)

                TextInput {
                    anchors.fill: parent
                    anchors.margins: 10
                    color: Theme.textPrimary
                    font: Theme.fontBody
                    text: "Enter a prompt..."
                }
            }

            NeonButton {
                text: "Generate"
                accent: Theme.accentMagenta
                onClicked: console.log("Generate clicked")
            }

            Text {
                text: "Status: Ready"
                font: Theme.fontCaption
                color: Theme.textSecondary
            }
        }
    }
}
