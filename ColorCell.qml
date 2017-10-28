import QtQuick 2.4

ColorCellForm {
    id: container
    MouseArea {
        anchors.fill: parent
        onClicked: container.clicked(container.cellColor, container.associatedLed)
    }
}
