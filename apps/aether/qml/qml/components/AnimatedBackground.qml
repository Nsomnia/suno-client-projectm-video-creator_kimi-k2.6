import QtQuick 2.15
import "../themes"

Item {
    anchors.fill: parent

    Rectangle {
        anchors.fill: parent
        color: Theme.bgDeep
    }

    Rectangle {
        id: orb1
        width: parent.width * 0.8
        height: width
        x: -parent.width * 0.2
        y: -parent.height * 0.3
        radius: width / 2
        gradient: Gradient {
            GradientStop { position: 0.0; color: Theme.accentPurple }
            GradientStop { position: 1.0; color: "transparent" }
        }
        opacity: 0.08

        SequentialAnimation on x {
            loops: Animation.Infinite
            NumberAnimation { to: parent.width * 0.1; duration: 14000; easing.type: Easing.InOutSine }
            NumberAnimation { to: -parent.width * 0.2; duration: 14000; easing.type: Easing.InOutSine }
        }
        SequentialAnimation on y {
            loops: Animation.Infinite
            NumberAnimation { to: parent.height * 0.1; duration: 12000; easing.type: Easing.InOutSine }
            NumberAnimation { to: -parent.height * 0.3; duration: 12000; easing.type: Easing.InOutSine }
        }
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            NumberAnimation { to: 0.14; duration: 8000; easing.type: Easing.InOutSine }
            NumberAnimation { to: 0.06; duration: 8000; easing.type: Easing.InOutSine }
        }
    }

    Rectangle {
        id: orb2
        width: parent.width * 0.6
        height: width
        x: parent.width * 0.5
        y: parent.height * 0.4
        radius: width / 2
        gradient: Gradient {
            GradientStop { position: 0.0; color: Theme.accentCyan }
            GradientStop { position: 1.0; color: "transparent" }
        }
        opacity: 0.06

        SequentialAnimation on x {
            loops: Animation.Infinite
            NumberAnimation { to: parent.width * 0.3; duration: 16000; easing.type: Easing.InOutSine }
            NumberAnimation { to: parent.width * 0.5; duration: 16000; easing.type: Easing.InOutSine }
        }
        SequentialAnimation on y {
            loops: Animation.Infinite
            NumberAnimation { to: parent.height * 0.2; duration: 10000; easing.type: Easing.InOutSine }
            NumberAnimation { to: parent.height * 0.4; duration: 10000; easing.type: Easing.InOutSine }
        }
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            NumberAnimation { to: 0.12; duration: 7000; easing.type: Easing.InOutSine }
            NumberAnimation { to: 0.04; duration: 7000; easing.type: Easing.InOutSine }
        }
    }

    Rectangle {
        id: orb3
        width: parent.width * 0.9
        height: width
        x: parent.width * 0.1
        y: parent.height * 0.6
        radius: width / 2
        gradient: Gradient {
            GradientStop { position: 0.0; color: Theme.bgSurface }
            GradientStop { position: 1.0; color: "transparent" }
        }
        opacity: 0.12

        SequentialAnimation on x {
            loops: Animation.Infinite
            NumberAnimation { to: parent.width * 0.05; duration: 18000; easing.type: Easing.InOutSine }
            NumberAnimation { to: parent.width * 0.1; duration: 18000; easing.type: Easing.InOutSine }
        }
        SequentialAnimation on y {
            loops: Animation.Infinite
            NumberAnimation { to: parent.height * 0.45; duration: 13000; easing.type: Easing.InOutSine }
            NumberAnimation { to: parent.height * 0.6; duration: 13000; easing.type: Easing.InOutSine }
        }
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            NumberAnimation { to: 0.18; duration: 9000; easing.type: Easing.InOutSine }
            NumberAnimation { to: 0.08; duration: 9000; easing.type: Easing.InOutSine }
        }
    }

    Rectangle {
        id: orb4
        width: parent.width * 0.5
        height: width
        x: parent.width * 0.2
        y: parent.height * 0.1
        radius: width / 2
        gradient: Gradient {
            GradientStop { position: 0.0; color: Theme.accentMagenta }
            GradientStop { position: 1.0; color: "transparent" }
        }
        opacity: 0.04

        SequentialAnimation on x {
            loops: Animation.Infinite
            NumberAnimation { to: parent.width * 0.35; duration: 15000; easing.type: Easing.InOutSine }
            NumberAnimation { to: parent.width * 0.2; duration: 15000; easing.type: Easing.InOutSine }
        }
        SequentialAnimation on y {
            loops: Animation.Infinite
            NumberAnimation { to: parent.height * 0.25; duration: 11000; easing.type: Easing.InOutSine }
            NumberAnimation { to: parent.height * 0.1; duration: 11000; easing.type: Easing.InOutSine }
        }
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            NumberAnimation { to: 0.09; duration: 6000; easing.type: Easing.InOutSine }
            NumberAnimation { to: 0.03; duration: 6000; easing.type: Easing.InOutSine }
        }
    }
}
