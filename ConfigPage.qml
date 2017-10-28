import QtQuick 2.4
import QtQuick.Controls 2.2

ConfigPageForm {
    id: configPage
    //redcell.onCompleted: {redcell.onClicked.connect(updateColor)}

    Component.onCompleted: {
        var ledArray = [redcell, greencell, bluecell, yellowcell, steelbluecell, blackcell];
        ledArray.forEach(function(elem){
            elem.onClicked.connect(updateColor);
        })
        //colorSliderText.onLineLaidOut.connect(updateColorSliderText)
        //colorSliderText.moved.connect(updateColorSliderText)
        //redcell.onClicked.connect(updateColor)
    }
    colorSliderText.onLineLaidOut: {updateColorSliderText()}
    //colorSlider.onMoved: {updateColorSliderText()}
    //redcell.onClicked: {updateColor(cellColour, ledToChange)}

    function updateColor(color) {
        homePage.chosenLed.color = color
        //ledbutton.color = color
        helloText.color = color
        tabBar.currentIndex = 0;
    }

    function updateColorSliderText(){
//        console.log("MEXEUEUEU")
//        if (colorSlider.value == 0) colorSliderText.text = "zero";
//        if (colorSlider.value == 1/3) colorSliderText.text = "vintecinco";
//        if (colorSlider.value == 2/3) colorSliderText.text = "cinquenta";
//        else colorSliderText.text = "cem";
        //colorSliderText.text = "eitcha"
    }
}
