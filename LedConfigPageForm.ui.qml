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
    property alias numblinksSlider: numblinksSlider
    property alias workcycleSlider: workcycleSlider
    property alias sendButton: sendButton
    // Texto com nome dos leds
    Pane{
        id: ledNamePane
        anchors.top: parent.top
        anchors.topMargin: 5
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
    // Seleção de tempo
    Pane{
        id: timingPane
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: slidersPane.bottom
        width: 0.7 * parent.width
        height: configPage.height - slidersPane.height - ledNamePane.height - sendPane.height - 10
        background: Rectangle {id: rowPaneBg; color: "#b3f7c2"; radius: slidersPane.height/20}
        padding: 5
        Row{
            id: timerRow
            anchors.fill: parent
            spacing: 5
            // Pane com o timer
            Pane{
                id: dialPane
                //width: parent.height > parent.width? parent.height * 1/3 : parent.width * 1/3
                width: parent.width * 1/3
                height: parent.height
                background: Rectangle{color:rowPaneBg.color}
                //background: Rectangle{color:"red"}
                TimerDial{
                    id: timerDial
                    dialHeight: dialPane.height > dialPane.width? dialPane.width : dialPane.height
                    anchors.centerIn: parent
                }
            }
            // Ciclo de trabalho e número de blinks
            Pane{
                id: timeConfigPane
                padding: 0
                width: timerRow.width - dialPane.width - timingPane.rightPadding
                height: parent.height
                background: Rectangle{color:rowPaneBg.color}
                // Ciclo de trabalho
                SliderWithLabel{
                    id: workcycleSlider
                    width: parent.width
                    height: 0.45 * parent.height
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 0
                    bg_color: rowPaneBg.color
                    slider.from: 10
                    slider.to: 100
                    slider.value: 100
                }
                // Número de blinks
                SliderWithLabel{
                    id: numblinksSlider
                    width: parent.width
                    height: 0.45 * parent.height
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.topMargin: 0
                    bg_color: rowPaneBg.color
                    slider.from: 0
                    slider.to: 10
                    slider.stepSize: 1
                    label.text: "Pisques: Permanente"
                }
            }
        }
    }
    // Botão de envio
    Pane{
        id: sendPane
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: timingPane.bottom
        width: 0.7 * parent.width
        height: 0.1 * configPage.height
        background: Rectangle {id: sendPaneBg; color: "#ffd87c"; radius: slidersPane.height/20}
        // Pane com o botão de enviar
        Pane{
            id: enviarPane
            width: sendPane.width * 1/2
            height: sendPane.height
            anchors.centerIn: parent
            background: Rectangle{color:sendPaneBg.color}
            //background: Rectangle{color:"red"}
            Button{
                id: sendButton
                enabled: homePage.connectionStatus == "Connected"? true : false
                anchors.centerIn: parent
                height: 0.9 * enviarPane.height
                width: enviarPane.width
                text: "Enviar configuração"
                font.pointSize: height? height/2 : 16
                //anchors.top: parent.top
                //anchors.topMargin: 12
                contentItem: Text {
                    id: innerText
                    text: sendButton.text
                    font: sendButton.font
                    opacity: enabled ? 1.0 : 0.3
                    color: sendButton.down ? "#df9d00" : "#f7bb2c"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    opacity: enabled ? 1 : 0.3
                    //color: sendButton.down? "#fffaee" : "white"
                    border.color: sendButton.down ? "#df9d00" : "#f7bb2c"
                    border.width: 1
                    radius: 2
                }
            }
        }
    }
}
