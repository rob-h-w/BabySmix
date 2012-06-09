import QtQuick 1.0

Rectangle {
    width: 100
    height: 100
    Text {
        text: qsTr("Press Alt+F4 to quit.")
        anchors {
            top: parent.top
            left: parent.left
            topMargin: parent.height * 0.01
            leftMargin: parent.width * 0.01
        }
        Component.onCompleted: console.debug("topMargin: "+anchors.topMargin)
    }
}
