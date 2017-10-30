import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    property alias dialHeight: dial.height
    property alias text: textObj.text
    property alias value: dial.value
    //height: 40
    Dial{
        //anchors.fill: parent
        id: dial
        from: 0
        to: 1
        stepSize: 0.1
        snapMode: "SnapAlways"
        height: parent.height
        width: height
        anchors.centerIn: parent
        background: Rectangle {
            x: dial.width / 2 - width / 2
            y: dial.height / 2 - height / 2
            width: Math.max(64, Math.min(dial.width, dial.height))
            height: width
            color: "#cefbd2"
            radius: width / 2
            border.color: dial.pressed ? "#17a81a" : "#21be2b"
            opacity: dial.enabled ? 1 : 0.3
        }

        handle: Rectangle {
            id: handleItem
            x: dial.background.x + dial.background.width / 2 - width / 2
            y: dial.background.y + dial.background.height / 2 - height / 2
            width: dial.width/10
            height: width
            color: dial.pressed ? "#17a81a" : "#21be2b"
            radius: width/2
            antialiasing: true
            opacity: dial.enabled ? 1 : 0.3
            transform: [
                Translate {
                    y: -Math.min(dial.background.width, dial.background.height) * 0.4 + handleItem.height / 2
                },
                Rotation {
                    angle: dial.angle
                    origin.x: handleItem.width / 2
                    origin.y: handleItem.height / 2
                }
            ]
        }
        Text{
            id: textObj
            anchors.centerIn: dial
            text: "PERM"
            font.pointSize: dial.height? (dial.height/4) * 8/6 : 16
        }
    }
}
