import QtQuick 1.0

Rectangle {
    id: root

    property alias text: message.text
    property int padding: 12
    anchors.centerIn: parent
    width: childrenRect.width + 2 * padding
    height: childrenRect.height + 2 * padding
    border.width: 1
    radius: 0.2 * width
    color: "#ccccff"
    smooth: true

    Text {
        id: message

        anchors {
            top: parent.top
            topMargin: root.padding
            left: parent.left
            leftMargin: root.padding
        }
    }
}
