import QtQuick 2.15
import "../themes"

Item {
    id: root
    property color glowColor: "transparent"
    default property alias contentItem: container.children

    implicitWidth: 200
    implicitHeight: 200

    // Glow layer
    Rectangle {
        visible: root.glowColor !== "transparent"
        anchors.fill: parent
        color: root.glowColor
        opacity: 0.25
        radius: Theme.radiusMedium + 8
        anchors.margins: -4
    }

    Rectangle {
        visible: root.glowColor !== "transparent"
        anchors.fill: parent
        color: root.glowColor
        opacity: 0.12
        radius: Theme.radiusMedium + 16
        anchors.margins: -8
    }

    // Main panel
    Rectangle {
        anchors.fill: parent
        radius: Theme.radiusMedium
        border.width: 1
        border.color: Qt.rgba(1, 1, 1, 0.08)
        gradient: Gradient {
            GradientStop { position: 0.0; color: Qt.rgba(1, 1, 1, 0.07) }
            GradientStop { position: 1.0; color: Qt.rgba(1, 1, 1, 0.03) }
        }
    }

    Item {
        id: container
        anchors.fill: parent
        anchors.margins: Theme.margin
    }
}
