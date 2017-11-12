import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    property alias button: button
    property alias text: button.text
    width: parent.width
    height: parent.height
    Pane{
        id: pane
        width: parent.width
        height: parent.height
        background: Rectangle{color: bg_color}
        Button{
            id: button
            anchors.centerIn: parent
            height: 0.8 * parent.parent.height
            width: parent.parent.width
            font.pointSize: height? height/2 : 16
            contentItem: Text {
                id: innerText
                text: button.text
                font: button.font
                opacity: enabled ? 1.0 : 0.3
                color: button.down ? "#388da7" : "#4CC7EC"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                opacity: enabled ? 1 : 0.3
                border.color: button.down ? "#388da7" : "#4CC7EC"
                border.width: 1
                radius: 2
            }
        }
    }
}
