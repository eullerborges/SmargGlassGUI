import QtQuick 2.4

ConfigPageForm {
    id: configPage
    //redcell.onCompleted: {redcell.onClicked.connect(updateColor)}

    Component.onCompleted: {
        var ledArray = [redcell, greencell, bluecell, yellowcell, steelbluecell, blackcell];
        ledArray.forEach(function(elem){
            elem.onClicked.connect(updateColor);
        })
        //redcell.onClicked.connect(updateColor)
    }
    //redcell.onClicked: {updateColor(cellColour, ledToChange)}

    function updateColor(color, ledbutton) {
        ledbutton.color = color
        helloText.color = color
    }
}
