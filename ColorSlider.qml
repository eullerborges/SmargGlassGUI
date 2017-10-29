import QtQuick 2.0
import QtQuick.Controls 2.2

Item{
    id: colorSlider
    property alias slider: slider
    property alias textItem: sliderText
    property alias value: slider.value
    property alias backgroundColor: background.color
    property alias foregroundColor: foreground.color
    property alias handleWidth: handleObj.width
    property alias textSize: sliderText.font.pointSize
    property alias textColor: sliderText.color
    signal intensityChanged(Item slider_changed)
    width: parent.width
    height: parent.height
    Slider {
        id: slider
        width: parent.width - sliderText.width
        height: parent.height
        anchors.left: parent.left
        anchors.leftMargin: (parent.width - (this.width + sliderText.width + 5 + sliderText.anchors.leftMargin))/2
        onValueChanged: intensityChanged(colorSlider)
        snapMode: "SnapAlways"
        stepSize: 1/3
        value: 0
        Text{
            id: sliderText
            anchors.left: parent.right
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: (colorSlider.height - this.height)/2
            text: "0 %"
            font.pointSize: 18
        }
        background: Rectangle {
            id: background
            x: slider.leftPadding
            y: slider.topPadding + slider.availableHeight / 2 - height / 2
            implicitWidth: 200
            implicitHeight: 4
            width: slider.availableWidth
            height: implicitHeight
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
        handle: Rectangle {
            id: handleObj
            x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
            y: slider.topPadding + slider.availableHeight / 2 - height / 2
            implicitWidth: 26
            implicitHeight: 26
            height: width
            radius: width/2
            color: slider.pressed ? "#f0f0f0" : "#f6f6f6"
            border.color: "#bdbebf"
        }
    }
}
