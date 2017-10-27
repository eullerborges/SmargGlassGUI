import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    Text {
            id: helloText
            text: "Hello world!"
            y: 30
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 24; font.bold: true
    }
    Grid {
           id: colorPicker
           x: 4; anchors.bottom: parent.bottom; anchors.bottomMargin: 4

           rows: 2; columns: 3; spacing: 3

           ColorCell { cellColor: "red"; onClicked: helloText.color = cellColor }
           ColorCell { cellColor: "green"; onClicked: helloText.color = cellColor }
           ColorCell { cellColor: "blue"; onClicked: helloText.color = cellColor }
           ColorCell { cellColor: "yellow"; onClicked: helloText.color = cellColor }
           ColorCell { cellColor: "steelblue"; onClicked: helloText.color = cellColor }
           ColorCell { cellColor: "black"; onClicked: helloText.color = cellColor }
    }
}
