import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: main_window
    visible: true
    width: 640
    height: 680
    title: qsTr("NiceGlass")
    property alias swipeView: swipeView
    property alias tabBar: tabBar
    property alias homePage: homePage

    minimumHeight: 250
    minimumWidth: 300

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        HomePage {
            id: homePage
        }
        ConfigPage {
            id: configPage
        }
    }

    footer: TabBar {
        id: tabBar
        height: main_window.height * 0.1
        currentIndex: swipeView.currentIndex
        TabButton {
            id: tabButtonInicio
            height: parent.height
            text: qsTr("Início")
            font.pointSize: parent.height? parent.height/1.5 : 20
            onPressed: {swipeView.setCurrentIndex(0)}
        }
        TabButton {
            id: tabButtonConfig
            height: parent.height
            text: qsTr("Configurações")
            font.pointSize: parent.height? parent.height/1.5 : 20
            onPressed: {swipeView.setCurrentIndex(1)}
        }
        onCurrentIndexChanged: {
            console.log("CHANGEDDDDD " + currentIndex )
        }
    }
}
