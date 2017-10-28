import QtQuick 2.4

Item {
    id: container
    property alias cellColor: rectangle.color
    property LedButton associatedLed: homePage.led1Button
    signal clicked(color cellColour, LedButton ledToChange)

    width: 40
    height: 25

    Rectangle {
        id: rectangle
        border.color: "white"
        anchors.fill: parent
    }
}
