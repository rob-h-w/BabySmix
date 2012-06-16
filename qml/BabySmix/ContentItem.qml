import QtQuick 1.0

Rectangle {
    id: root

    property real percentSize: 15
    property alias lifespan: lifespanTimer.interval
    scale: 3
    opacity: 0
    rotation: 360 * Math.random() - 180
    width: childrenRect.width
    height: childrenRect.height
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
            PropertyChanges { target: root; rotation: Math.random() * 180 - 90 }
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
