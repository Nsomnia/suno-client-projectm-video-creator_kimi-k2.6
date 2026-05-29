import QtQuick

Window {
    id: root
    visible: true
    width: 1280
    height: 720
    title: "Aether"

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#0a0a0f" }
            GradientStop { position: 1.0; color: "#1a1a2e" }
        }

        Text {
            anchors.centerIn: parent
            text: "AETHER // SYSTEM INITIALIZING"
            color: "#00d4ff"
            font.pixelSize: 32
            font.family: "Courier"
            font.bold: true

            SequentialAnimation on opacity {
                loops: Animation.Infinite
                NumberAnimation { to: 0.3; duration: 1200; easing.type: Easing.InOutQuad }
                NumberAnimation { to: 1.0; duration: 1200; easing.type: Easing.InOutQuad }
            }
        }

        Text {
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 12
            text: Version.commit + " | v" + Version.version
            color: "#888899"
            font.pixelSize: 11
            font.family: "Courier"
            opacity: 0.7
        }
    }
}
