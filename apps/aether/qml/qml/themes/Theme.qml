pragma Singleton
import QtQuick 2.15

QtObject {
    // Colors
    property color bgDeep: "#05050a"
    property color bgSurface: "#0f0f1a"
    property color bgElevated: "#1a1a2e"
    property color accentCyan: "#00f0ff"
    property color accentMagenta: "#ff00aa"
    property color accentPurple: "#7b2dff"
    property color textPrimary: "#ffffff"
    property color textSecondary: "#a0a0b0"
    property color borderGlow: "#00f0ff"

    // Metrics
    property int radiusSmall: 6
    property int radiusMedium: 12
    property int radiusLarge: 20
    property int margin: 16
    property int navHeight: 64

    // Typography
    property font fontHeader: ({ family: "Roboto", pixelSize: 28, weight: Font.Bold })
    property font fontBody: ({ family: "Roboto", pixelSize: 14, weight: Font.Normal })
    property font fontCaption: ({ family: "Roboto", pixelSize: 11, weight: Font.Light })
}
