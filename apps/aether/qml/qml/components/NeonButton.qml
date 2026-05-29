import QtQuick 2.15
import "../themes"

Rectangle {
    id: root
    property string text: ""
    property color accent: Theme.accentCyan
    signal clicked()

    width: label.implicitWidth + 40
    height: label.implicitHeight + 20
    radius: Theme.radiusSmall
    color: "#12121e"
    border.width: hovered ? 1.5 : 1
    border.color: hovered ? root.accent : Qt.rgba(1, 1, 1, 0.1)

    property bool hovered: false

    Text {
        id: label
        anchors.centerIn: parent
        text: root.text
        font: Theme.fontBody
        color: root.hovered ? Theme.textPrimary : Theme.textSecondary
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: root.hovered = true
        onExited: root.hovered = false
        onPressed: scaleAnim.to = 0.97
        onReleased: scaleAnim.to = 1.0
        onClicked: root.clicked()
    }

    Behavior on border.color {
        ColorAnimation { duration: 200 }
    }

    NumberAnimation on scale {
        id: scaleAnim
        to: 1.0
        duration: 100
        easing.type: Easing.OutQuad
    }
}
