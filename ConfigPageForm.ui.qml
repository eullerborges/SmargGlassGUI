import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
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

           ColorCell { id: redcell; cellColor: "red"; associatedLed: homePage.led1Button}
           ColorCell { id: greencell; cellColor: "green"; associatedLed: homePage.led1Button}
           ColorCell { id: bluecell; cellColor: "blue"; associatedLed: homePage.led1Button}
           ColorCell { id: yellowcell; cellColor: "yellow"; associatedLed: homePage.led2Button}
           ColorCell { id: steelbluecell; cellColor: "steelblue"; associatedLed: homePage.led2Button}
           ColorCell { id: blackcell; cellColor: "black"; associatedLed: homePage.led2Button}
    }
}
