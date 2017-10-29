import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
Item {
    id: configPage
    property alias redColorSlider: redColorSlider
    property alias greenColorSlider: greenColorSlider
    property alias blueColorSlider: blueColorSlider

    property alias ledName: ledName
    // Texto com nome dos leds
    Pane{
        id: ledNamePane
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: 0.7 * parent.width
        background: Rectangle {color: "#5294a8"; radius: 10}
        Text {
            id: ledName
            text: homePage.chosenLed.name
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"
            font.pointSize: configPage.height? configPage.height/10 : 16;
            font.bold: true
        }
    }
    // Pane com os sliders das cores
    Pane{
        id: slidersPane
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: ledNamePane.bottom
        anchors.topMargin: 0
        width: 0.7 * parent.width
        //height: redColorSlider.handleWidth * 3 + sliderColumns.spacing * 3 + 20
        background: Rectangle {id: pane_bg; color: "#b3e7f7"; radius: 10}
        Column{
            id: sliderColumns
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            width: parent.width
            spacing: 5
            Pane{
                width: parent.width
                height: redColorSlider.handleWidth
                background: Rectangle{color: pane_bg.color}
                ColorSlider{
                    id: redColorSlider
                    anchors.centerIn: parent
                    handleWidth: configPage.height/10
                    textSize: handleWidth? handleWidth * 0.65 : 16
                    foregroundColor: "#ff5555"
                }
            }
            Pane{
                width: parent.width
                height: greenColorSlider.handleWidth
                background: Rectangle{color: pane_bg.color}
                ColorSlider{
                    id: greenColorSlider
                    handleWidth: configPage.height/10
                    textSize: handleWidth? handleWidth * 0.65 : 16
                    anchors.centerIn: parent
                    foregroundColor: "#21be2b"
                }
            }
            Pane{
                width: parent.width
                height: blueColorSlider.handleWidth
                background: Rectangle{color: pane_bg.color}
                ColorSlider{
                    id: blueColorSlider
                    handleWidth: configPage.height/10
                    textSize: handleWidth? handleWidth * 0.65 : 16
                    anchors.centerIn: parent
                    foregroundColor: "#5555ff"
                }
            }
        }
    }
    Pane{
       id: timerPane
       anchors.top: slidersPane.bottom
       anchors.horizontalCenter: parent.horizontalCenter
       Dial{
           id: timerDial
           height: configPage.height - slidersPane.height - ledNamePane.height - tabBar.height
           from: 0
           to: 1
           stepSize: 0.1
           snapMode: "SnapAlways"
           Text{
               anchors.centerIn: timerDial
               text: "0.00 s"
               font.pointSize: (timerDial.height/4) * 8/6;
           }
       }
    }
}
