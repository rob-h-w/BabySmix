import QtQuick 1.0

ContentItem {
    id: root

    property alias text: text.text
    Text {
        id: text
        color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0)
        font.pixelSize: rootHeight ? rootHeight * root.percentSize/100 : root.percentSize
        font.bold: true
        style: Text.Outline
        styleColor: "black"
        smooth: true
    }
}
