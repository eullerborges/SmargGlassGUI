import QtQuick 2.4
import QtQuick.Controls 2.2

Item {
    property alias colorSliderText: colorSliderText
    property alias colorSlider: colorSlider

    property alias helloText: helloText
    property alias redcell: redcell
    property alias greencell: greencell
    property alias bluecell: bluecell
    property alias yellowcell: yellowcell
    property alias steelbluecell: steelbluecell
    property alias blackcell: blackcell
    Text {
            id: helloText
            text: homePage.chosenLed.name
            y: 30
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 24; font.bold: true
    }
    Grid {
           id: colorPicker
           x: 4; anchors.bottom: parent.bottom; anchors.bottomMargin: 4

           rows: 2; columns: 3; spacing: 3

           ColorCell { id: redcell; cellColor: "red"}
           ColorCell { id: greencell; cellColor: "green"}
           ColorCell { id: bluecell; cellColor: "blue"}
           ColorCell { id: yellowcell; cellColor: "yellow"}
           ColorCell { id: steelbluecell; cellColor: "steelblue"}
           ColorCell { id: blackcell; cellColor: "black"}
    }

    Slider {
        id: colorSlider
        x: 20
        y: 45
        anchors.horizontalCenter: parent.horizontalCenter
        snapMode: "SnapAlways"
        stepSize: 1/3
        value: 0
        Text{
            id: colorSliderText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.bottom
            text: parent.value
            font.pointSize: 18
        }
    }
}
