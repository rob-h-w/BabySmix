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
import "utils.js" as U

Rectangle {
    id: root

    property real percentSize: 15
    property alias lifespan: lifespanTimer.interval
    scale: 3
    opacity: 0
    rotation: U.randomPlusMinus(0, 180)
    width: childrenRect.width
    height: childrenRect.height
    x: U.randomMinMax(0, parent.width - width)
    y: U.randomMinMax(0, parent.height - height)

    color: "transparent"
    states: [
        State {
            name: ""
        },
        State {
            name: "shown"
            PropertyChanges { target: root; scale: 1 }
            PropertyChanges { target: root; opacity: 1 }
            PropertyChanges { target: root; rotation: 0 }
        },
        State {
            name: "tailOff"
            PropertyChanges { target: root; scale: 0 }
            PropertyChanges { target: root; opacity: 0 }
            PropertyChanges { target: root; rotation: U.randomPlusMinus(0, 90) }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "shown"
            SequentialAnimation {
                ParallelAnimation {
                    // Visual effects.
                    NumberAnimation { target: root; property: "scale"; duration: 500; easing.type: Easing.OutElastic }
                    NumberAnimation { target: root; property: "opacity"; duration: 200 }
                    NumberAnimation { target: root; property: "rotation"; duration: 500 }
                }
                // Cleanup
                ScriptAction {
                    script: lifespanTimer.start()
                }
            }
        },
        Transition {
            from: "shown"
            to: "tailOff"
            SequentialAnimation {
                ParallelAnimation {
                    // Visual effects.
                    NumberAnimation { target: root; property: "scale"; duration: 5000 }
                    NumberAnimation { target: root; property: "opacity"; duration: 5000 }
                    NumberAnimation { target: root; property: "rotation"; duration: 5000 }
                }
                // Cleanup
                ScriptAction {
                    script: root.destroy()
                }
            }
        }
    ]

    Timer {
        id: lifespanTimer

        interval: 5000
        onTriggered: root.state = "tailOff"
    }

    Component.onCompleted: {
        state = "shown"
    }
}
