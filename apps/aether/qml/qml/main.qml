import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "themes"
import "components"
import "pages"

Window {
    id: root
    visible: true
    width: 1280
    height: 720
    title: "Aether // Multimedia Workstation"
    color: Theme.bgDeep

    AnimatedBackground {
        anchors.fill: parent
    }

    StackView {
        id: stackView
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: navBar.top
        initialItem: visualizerPage

        replaceEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: 250
            }
            PropertyAnimation {
                property: "x"
                from: 50
                to: 0
                duration: 250
                easing.type: Easing.OutQuad
            }
        }
        replaceExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to: 0
                duration: 250
            }
            PropertyAnimation {
                property: "x"
                from: 0
                to: -50
                duration: 250
                easing.type: Easing.OutQuad
            }
        }
    }

    Component { id: visualizerPage; VisualizerPage {} }
    Component { id: libraryPage; LibraryPage {} }
    Component { id: sunoPage; SunoPage {} }
    Component { id: settingsPage; SettingsPage {} }

    GlassPanel {
        id: navBar
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: Theme.navHeight

        Row {
            anchors.centerIn: parent
            spacing: 48

            NavButton {
                icon: "\u25A0"
                label: "Visualizer"
                active: stackView.currentItem instanceof VisualizerPage
                onClicked: {
                    if (!(stackView.currentItem instanceof VisualizerPage))
                        stackView.replace(visualizerPage)
                }
            }

            NavButton {
                icon: "\u2630"
                label: "Library"
                active: stackView.currentItem instanceof LibraryPage
                onClicked: {
                    if (!(stackView.currentItem instanceof LibraryPage))
                        stackView.replace(libraryPage)
                }
            }

            NavButton {
                icon: "\u266A"
                label: "Suno"
                active: stackView.currentItem instanceof SunoPage
                onClicked: {
                    if (!(stackView.currentItem instanceof SunoPage))
                        stackView.replace(sunoPage)
                }
            }

            NavButton {
                icon: "\u2699"
                label: "Settings"
                active: stackView.currentItem instanceof SettingsPage
                onClicked: {
                    if (!(stackView.currentItem instanceof SettingsPage))
                        stackView.replace(settingsPage)
                }
            }
        }
    }

    Text {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 12
        text: Version.commit + " | v" + Version.version
        color: Theme.textSecondary
        font: Theme.fontCaption
        opacity: 0.7
    }
}
