import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    id: configPage
    property alias redColorSlider: redColorSlider
    property alias greenColorSlider: greenColorSlider
    property alias blueColorSlider: blueColorSlider

    property alias helloText: ledName
    property alias redcell: redcell
    property alias greencell: greencell
    property alias bluecell: bluecell
    property alias yellowcell: yellowcell
    property alias steelbluecell: steelbluecell
    property alias blackcell: blackcell
    Text {
        id: ledName
        text: homePage.chosenLed.name
        anchors.top: parent.top
        anchors.topMargin: 20
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

    Column{
        id: sliderColumns
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: ledName.bottom
        anchors.topMargin: 10
        width: 0.6 * parent.width
        spacing: 5
        Rectangle{
            width: parent.width
            height: 30
            ColorSlider{
                id: redColorSlider
                anchors.centerIn: parent
                foregroundColor: "#ff5555"
            }
        }
        Rectangle{
            width: parent.width
            height: 30
            ColorSlider{
                id: greenColorSlider
                anchors.centerIn: parent
                foregroundColor: "#21be2b"
            }
        }
        Rectangle{
            width: parent.width
            height: 30
            ColorSlider{
                id: blueColorSlider
                anchors.centerIn: parent
                foregroundColor: "#5555ff"
            }
        }
    }
}
