import QtQuick 1.0

Rectangle {
    id: root

    property alias text: text.text
    property real percentSize: 15
    color: "transparent"

    Text {
        id: text
        color: Qt.rgba(Math.random(), Math.random(), Math.random(), 255)
        font.pixelSize: rootHeight ? rootHeight * root.percentSize/100 : root.percentSize
        font.bold: true
        style: Text.Outline
        styleColor: "black"
        Component.onCompleted: console.debug("color: "+color+", height: "+font.pixelSize)
    }
}
