import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

Item {
    id: homePage
    width: 150
    height: 100

    property alias led1Button: led1
    property alias led2Button: led2
    property LedButton chosenLed: led1
    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
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
                source: "resources/round-compliment.png"
            }
            LedButton {
                id: led1
                name: "led1"
                anchors.leftMargin: 40
                anchors.topMargin: 41
            }
            LedButton {
                id: led2
                name: "led2"
                anchors.leftMargin: 10
                anchors.topMargin: 50
            }
        }
    }
}
