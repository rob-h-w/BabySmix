import QtQuick 1.0

Rectangle {
    id: root

    property real percentSize: 15
    property alias lifespan: lifespanTimer.interval
    width: childrenRect.width
    height: childrenRect.height
    color: "transparent"

    Timer {
        id: lifespanTimer

        running: true
        interval: 3000
        onTriggered: root.destroy()
    }
}
