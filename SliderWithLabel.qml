/**
  Implementação de um slider com um label associado.
  */
import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    property real labelProportion: 0.3  // Proporção do label em relação ao conjunto
    property alias slider: slider  // Alias para o QtQuick Control Slider
    property alias label: label  // Alias para o QtQuick Control label
    property color bg_color: "white"
    property alias value: slider.value
    Pane{
        id: sliderPane
        height: (1 - labelProportion) * parent.height
        width: parent.width
        implicitHeight: 30
        implicitWidth: 150
        background: Rectangle{color: bg_color}
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        padding: 0
        //                        anchors.left: parent.left
        Slider{
            id: slider
            anchors.centerIn: parent
            height: 0.8 * parent.height
            width: parent.width
            orientation: Qt.Horizontal
            snapMode: Slider.SnapAlways
            handle.width: height
            handle.height: height
//            background.height: height/8
            from: 0
            to: 100
            stepSize: 10
            background: Rectangle {
                id: background
                x: slider.leftPadding
                y: slider.topPadding + slider.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 4
                width: slider.availableWidth
                height: slider.height/8
                radius: 2
                color: "#bdbebf"

                Rectangle {
                    id: foreground
                    width: slider.visualPosition * parent.width
                    height: parent.height
                    color: "#21be2b"
                    radius: 2
                }
            }
        }
    }
    Pane{
        id: labelPane
        anchors.top: sliderPane.bottom
        anchors.horizontalCenter: sliderPane.horizontalCenter
        height: labelProportion * parent.height
        padding: 0
        width: parent.parent.width
        background: Rectangle {color: bg_color}
        Label{
            id: label
            anchors.centerIn: parent
            anchors.top: parent.top
            text: "Dummy Text"
            //text: slider.value + " %"
            //text: parseInt(slider.value) + " %"
            font.pixelSize: 0.8 * parent.height
            fontSizeMode: Text.Fit
            //elide: Text.ElideLeft
            //width: text.width*font.pixelSize > parent.width? parent.width : text.width * font.pixelSize
        }
    }
}
