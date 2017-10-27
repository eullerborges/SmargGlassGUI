import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("NiceGlass")
    property alias swipeView: swipeView
    property alias tabBar: tabBar

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        HomePage {
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
