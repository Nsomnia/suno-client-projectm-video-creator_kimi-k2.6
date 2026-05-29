import QtQuick 2.15
import "../themes"

Item {
    id: root
    property string icon: ""
    property string label: ""
    property bool active: false
    signal clicked()

    width: 80
    height: Theme.navHeight

    Column {
        anchors.centerIn: parent
        spacing: 4

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: root.icon
            font.pixelSize: 20
            color: root.active ? Theme.accentCyan : Theme.textSecondary
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            text: root.label
            font: Theme.fontCaption
            color: root.active ? Theme.textPrimary : Theme.textSecondary
        }
    }

    Rectangle {
        id: indicator
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: 32
        height: 2
        color: Theme.accentCyan
        opacity: root.active ? 1.0 : 0.0
        y: root.active ? 0 : -4
    }

    Behavior on opacity {
        NumberAnimation { duration: 200 }
    }

    states: State {
        when: root.active
        PropertyChanges { target: indicator; opacity: 1.0; y: 0 }
    }

    transitions: Transition {
        NumberAnimation { properties: "opacity,y"; duration: 250; easing.type: Easing.OutQuad }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
