import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
Item {
    id: configPage
    property alias redColorSlider: redColorSlider
    property alias greenColorSlider: greenColorSlider
    property alias blueColorSlider: blueColorSlider

    property alias ledName: ledName
    property alias timerDial: timerDial
    property alias sendButton: sendButton
    // Texto com nome dos leds
    Pane{
        id: ledNamePane
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: 0.7 * parent.width
        background: Rectangle {color: "#5294a8"; radius: slidersPane.height/20}
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
        background: Rectangle {id: pane_bg; color: "#b3e7f7"; radius: slidersPane.height/20}
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
    // Seleção de tempo + botão de envio
    Pane{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: slidersPane.bottom
        width: 0.7 * parent.width
        height: configPage.height - slidersPane.height - ledNamePane.height - 10
        background: Rectangle {id: rowPaneBg; color: "#b3f7c2"; radius: slidersPane.height/20}
        Row{
            id: timerRow
            anchors.fill: parent
            spacing: 5
            // Pane com o timer
            Pane{
                id: timerPane
                width: parent.width * 2/3
                height: parent.height
                background: Rectangle{color:rowPaneBg.color}
                //background: Rectangle{color:"red"}
                TimerDial{
                    id: timerDial
                    height: timerRow.height
                    anchors.centerIn: parent
                }
            }
            // Pane com o botão de enviar
            Pane{
                id: enviarPane
                width: parent.width * 1/3
                height: parent.height
                background: Rectangle{color:rowPaneBg.color}
                Button{
                    id: sendButton
                    enabled: homePage.connectionStatus == "Connected"? true : false
                    anchors.centerIn: parent
                    height: timerRow.height/2
                    width: timerRow.width/4
                    text: "Enviar \n configuração"
                    font.pointSize: height? height/4 : 16
                    //anchors.top: parent.top
                    //anchors.topMargin: 12
                    contentItem: Text {
                        id: innerText
                        text: sendButton.text
                        font: sendButton.font
                        opacity: enabled ? 1.0 : 0.3
                        color: sendButton.down ? "#17a81a" : "#21be2b"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 40
                        opacity: enabled ? 1 : 0.3
                        border.color: sendButton.down ? "#17a81a" : "#21be2b"
                        border.width: 1
                        radius: 2
                    }
                }
            }
        }
    }
}
