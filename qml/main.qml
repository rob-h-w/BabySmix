//    BabySmix - Ubuntu targetted baby game based on and inspired by Scott
//    Hanselman's much-loved Baby Smash! http://www.hanselman.com/babysmash/
//    Copyright (C) 2012  Rob Williamson
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
import QtQuick 1.0

Rectangle {
    id: root

    function onKeyPressed(key) {
        var characterList = qsTr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
        var object
        if (characterList.indexOf(key) !== -1)
            object = characterComponent.createObject(root, { "text": key })
        else
            object = makeShape()

        if (undefined !== object.initialize)
            object.initialize()
    }

    function makeShape() {
        var object
        switch(Math.floor(Math.random() * 1.99))
        {
        case 0:
            object = squareComponent.createObject(root)
            break;
        default:
            object = rectangleComponent.createObject(root)
            break;
        }

        return object
    }

    property bool started: false

    width: rootWidth ? rootWidth : 0
    height: rootHeight ? rootHeight : 0

    MouseArea {
        id:mouseArea

        anchors.fill: parent

        onClicked: root.started = true
    }

    ClickMe {
        visible: !root.started
        text: qsTr("Click anywhere to begin!")
    }

    Text {
        text: qsTr("Version %0.\nPress Alt+F4 to quit.").arg(version)
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

    Component {
        id: squareComponent
        SquareItem {
            x: Math.random() * rootWidth - width/2
            y: Math.random() * rootHeight - height/2
        }
    }

    Component {
        id: rectangleComponent
        RectangleItem {
            x: Math.random() * rootWidth - width/2
            y: Math.random() * rootHeight - height/2
        }
    }
}
