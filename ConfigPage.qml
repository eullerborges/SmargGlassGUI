import QtQuick 2.9
import QtQuick.Controls 2.2

ConfigPageForm {
    id: configPage
    Component.onCompleted: {
        redColorSlider.onIntensityChanged.connect(updateColorSliderText)
        greenColorSlider.onIntensityChanged.connect(updateColorSliderText)
        blueColorSlider.onIntensityChanged.connect(updateColorSliderText)
        console.log("Final: " + redColorSlider.textSize)
    }
    redColorSlider.onTextSizeChanged: {
        console.log("Changed: " + redColorSlider.textSize)
    }

    function updateColor(color) {
        homePage.chosenLed.color = color
        helloText.color = color
        tabBar.currentIndex = 0;
    }

    function updateColorSliderText(slider_changed){
        if (slider_changed.value == 0) slider_changed.textItem.text = "0 %";
        else if (slider_changed.value == 1/3) slider_changed.textItem.text = "25 %";
        else if (slider_changed.value == 2/3) slider_changed.textItem.text = "50 %";
        else if (slider_changed.value == 1) slider_changed.textItem.text = "100 %";
        //colorSliderText.text = "eitcha"
    }
}
