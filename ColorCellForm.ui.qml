import QtQuick 2.4

Item {
    id: container
    property alias cellColor: rectangle.color
    signal clicked(color cellColour)

    width: 40
    height: 25

    Rectangle {
        id: rectangle
        border.color: "white"
        anchors.fill: parent
    }
}
