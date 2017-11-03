import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

Item {
    id: homePage

    property alias glassImage: glassImage
    property list<LedButton> ledButtons
    property alias connectionStatus: infoPane.connectionStatus
    property alias infoPaneStatusLabel: infoPaneStatusLabel
    property alias serialConfigButton: serialConfigButton
    property LedButton chosenLed: led1
    property color bg_color: "#b3e7f7"

    ledButtons: [led1, led2, led3, led4, led5, led6, led7, led8, led9, led10,
        led11, led12, led13, led14, led15, led16, led17, led18, led19, led20]
    Pane{
        id: background
        anchors.fill: parent
        background: Rectangle {color: bg_color}
        Pane {
            id: pane
            background: Rectangle {color: bg_color}
            //anchors.fill: parent
            height: parent.height - infoPane.height
            width: parent.width
            Image {
                id: glassImage
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                antialiasing: true
                smooth: true
                sourceSize.width: 2048
                sourceSize.height: 622
                source: "resources/glass_image.png"
                LedButton {id: led1; name: "LED 1"; leftMarginModifier: 0.1275; topMarginModifier: 0.052412}
                LedButton {id: led2; name: "LED 2"; leftMarginModifier: 0.0625; topMarginModifier: 0.204412}
                LedButton {id: led3; name: "LED 3"; leftMarginModifier: 0.0725; topMarginModifier: 0.494412}
                LedButton {id: led4; name: "LED 4"; leftMarginModifier: 0.1075; topMarginModifier: 0.804412}
                LedButton {id: led5; name: "LED 5"; leftMarginModifier: 0.2025; topMarginModifier: 0.940412}
                LedButton {id: led6; name: "LED 6"; leftMarginModifier: 0.3225; topMarginModifier: 0.920412}
                LedButton {id: led7; name: "LED 7"; leftMarginModifier: 0.4005; topMarginModifier: 0.720412}
                LedButton {id: led8; name: "LED 8"; leftMarginModifier: 0.2375; topMarginModifier: 0.052412}
                LedButton {id: led9; name: "LED 9"; leftMarginModifier: 0.3375; topMarginModifier: 0.096012}
                LedButton {id: led10; name: "LED 10"; leftMarginModifier: 0.4405; topMarginModifier: 0.223412}


                LedButton {id: led11; name: "LED 11"; leftMarginModifier: 1 - led1.leftMarginModifier; topMarginModifier: led1.topMarginModifier}
                LedButton {id: led12; name: "LED 12"; leftMarginModifier: 1 - led2.leftMarginModifier; topMarginModifier: led2.topMarginModifier}
                LedButton {id: led13; name: "LED 13"; leftMarginModifier: 1 - led3.leftMarginModifier; topMarginModifier: led3.topMarginModifier}
                LedButton {id: led14; name: "LED 14"; leftMarginModifier: 1 - led4.leftMarginModifier; topMarginModifier: led4.topMarginModifier}
                LedButton {id: led15; name: "LED 15"; leftMarginModifier: 1 - led5.leftMarginModifier; topMarginModifier: led5.topMarginModifier}
                LedButton {id: led16; name: "LED 16"; leftMarginModifier: 1 - led6.leftMarginModifier; topMarginModifier: led6.topMarginModifier}
                LedButton {id: led17; name: "LED 17"; leftMarginModifier: 1 - led7.leftMarginModifier; topMarginModifier: led7.topMarginModifier}
                LedButton {id: led18; name: "LED 18"; leftMarginModifier: 1 - led8.leftMarginModifier; topMarginModifier: led8.topMarginModifier}
                LedButton {id: led19; name: "LED 19"; leftMarginModifier: 1 - led9.leftMarginModifier; topMarginModifier: led9.topMarginModifier}
                LedButton {id: led20; name: "LED 20"; leftMarginModifier: 1 - led10.leftMarginModifier; topMarginModifier: led10.topMarginModifier}
            }
        }
        Pane{
            id: infoPane
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 5
            width: 0.8 * parent.width
            height: 0.1 * parent.height
            property string connectionStatus: "Disconnected"
            background: Rectangle {color: bg_color; border.color: "#388da7"; radius: width/36; border.width: 1}
            Row{
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: parent.width/20
                Label{
                    id: infoPaneLabel1
                    text: "Status: "
                    color: infoPane.background.border.color
                    font.pixelSize: infoPane.height/3
                }
                Label{
                    id: infoPaneStatusLabel
                    text: "Disconnected"
                    color: "red"
                    font.pixelSize: infoPane.height/3
                }
            }
            Pane{
                id: serialConfigPane
                width: infoPane.width * 1/3
                height: infoPane.height - 2 * infoPane.background.border.width
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: width/10
                background: Rectangle{color: bg_color}
                Button{
                    id: serialConfigButton
                    anchors.centerIn: parent
                    height: 0.8 * parent.parent.height
                    width: parent.parent.width
                    text: "Serial Config"
                    font.pointSize: height? height/2 : 16
                    contentItem: Text {
                        id: innerText
                        text: serialConfigButton.text
                        font: serialConfigButton.font
                        opacity: enabled ? 1.0 : 0.3
                        color: serialConfigButton.down ? "#388da7" : "#4CC7EC"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 40
                        opacity: enabled ? 1 : 0.3
                        border.color: serialConfigButton.down ? "#388da7" : "#4CC7EC"
                        border.width: 1
                        radius: 2
                    }
                }
            }
        }
    }
}
