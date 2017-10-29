import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 680
    title: qsTr("NiceGlass")
    property alias swipeView: swipeView
    property alias tabBar: tabBar
    property alias homePage: homePage

    minimumHeight: 335
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
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Início")
        }
        TabButton {
            text: qsTr("Configurações")
        }
    }
}
