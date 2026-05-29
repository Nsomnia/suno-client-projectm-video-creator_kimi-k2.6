import QtQuick 2.15
import Aether.Rendering 1.0
import "../themes"
import "../components"

Item {
    AnimatedBackground {
        anchors.fill: parent
    }

    // Top metadata overlay
    GlassPanel {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Theme.margin
        height: 80
        glowColor: Theme.accentCyan

        Column {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            spacing: 4

            Text {
                text: "Unknown Artist"
                font: Theme.fontHeader
                color: Theme.textPrimary
            }

            Text {
                text: "No Track Loaded"
                font: Theme.fontBody
                color: Theme.textSecondary
            }
        }
    }

    // Central visualizer canvas
    GlassPanel {
        anchors.centerIn: parent
        width: parent.width * 0.6
        height: parent.height * 0.5
        glowColor: Theme.accentPurple

        VisualizerItem {
            anchors.fill: parent
            anchors.margins: 8
            intensity: 1.0
        }
    }

    // Bottom playback controls
    GlassPanel {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Theme.margin
        height: 80
        glowColor: Theme.accentCyan

        Row {
            anchors.centerIn: parent
            spacing: 24

            NeonButton {
                text: "Previous"
                onClicked: console.log("Previous")
            }

            NeonButton {
                text: "Play"
                accent: Theme.accentMagenta
                onClicked: console.log("Play/Pause")
            }

            NeonButton {
                text: "Next"
                onClicked: console.log("Next")
            }
        }
    }
}
