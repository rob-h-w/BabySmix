import QtQuick 1.0

Rectangle {
    id: root

    function onKeyPressed(key) {
        var characterList = qsTr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
        if (characterList.indexOf(key) != -1)
            characterComponent.createObject(root, { "text": key })
    }

    width: rootWidth ? rootWidth : 0
    height: rootHeight ? rootHeight : 0
    Text {
        text: qsTr("Press Alt+F4 to quit.")
        z: 1000
        anchors {
            top: parent.top
            left: parent.left
            topMargin: parent.height * 0.01
            leftMargin: parent.width * 0.01
        }
        font.pixelSize: parent.height * 0.03
        style: Text.Outline
        styleColor: "white"
    }

    Component {
        id: characterComponent
        CharacterItem {
            x: Math.random() * rootWidth - width/2
            y: Math.random() * rootHeight - height/2
        }
    }
}
