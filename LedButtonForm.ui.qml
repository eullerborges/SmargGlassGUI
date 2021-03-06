import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    id: button
    width: 10
    height: 10
    anchors.top: parent.top
    anchors.left: parent.left
    property alias buttonText: innerText.text;
    property color color: "white"
    property color hoverColor: "#aaaaaa"
    property color pressColor: "slategray"
    property int fontSize: 10
    property int borderWidth: 1
    scale: state === "Pressed" ? 0.96 : 1.0
    onEnabledChanged: state = ""
    signal clicked
    signal chosen(Item thisled)

    //Rectangle to draw the button
    Rectangle {
        id: rectangleButton
        anchors.fill: parent
        radius: width
        color: button.enabled ? button.color : "grey"
        border.width: borderWidth
        border.color: "black"

        Text {
            id: innerText
            font.pointSize: fontSize
            anchors.centerIn: parent
        }
    }

    //change the color of the button in differen button states
    states: [
        State {
            name: "Hovering"
            PropertyChanges {
                target: rectangleButton
                //opacity: 0.8
                color: hoverColor
            }
        },
        State {
            name: "Pressed"
            PropertyChanges {
                target: rectangleButton
                color: pressColor
            }
        }
    ]
}
