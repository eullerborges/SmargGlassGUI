import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

Item {
    id: homePage

    property alias glassImage: glassImage
    property list<LedButton> ledButtons
    property alias led1Button: led1
    property alias led2Button: led2
    property LedButton chosenLed: led1

    ledButtons: [led1, led2, led3, led4, led5, led6, led7, led8, led9, led10,
                 led11, led12, led13, led14, led15, led16, led17, led18, led19, led20]

    Pane {
        id: pane
        background: Rectangle {
            color: "#b3e7f7"
        }
        anchors.fill: parent
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
}
