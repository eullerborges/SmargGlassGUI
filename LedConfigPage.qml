import QtQuick 2.9
import QtQuick.Controls 2.2

LedConfigPageForm {
    id: ledConfigPage
    Component.onCompleted: {
        redColorSlider.onIntensityChanged.connect(updateColorSliderText)
        greenColorSlider.onIntensityChanged.connect(updateColorSliderText)
        blueColorSlider.onIntensityChanged.connect(updateColorSliderText)
    }
    // Setando o texto do slider do ciclo de trabalho
    workcycleSlider.label.text: "Ciclo de trab.: " +  parseInt(workcycleSlider.slider.value) + " %"
    // Botão de enviar envia a configuração para o óculos.
    sendButton.onClicked: {
        swipeView.setCurrentIndex(0);
        var redValue = getRgbFromSliderPosition(redColorSlider.value);
        var greenValue = getRgbFromSliderPosition(greenColorSlider.value);
        var blueValue = getRgbFromSliderPosition(blueColorSlider.value);
        var period = timerDial.value;
        var workcycle = workcycleSlider.value/100;
        var blinks = parseInt(numblinksSlider.value);
        //console.log("P: " + period + " WC: " + workcycle + " BL: " + blinks)
        backend.sendNewLedConfig(homePage.chosenLed.no, redValue, greenValue, blueValue, period, workcycle, blinks);
    }

    // Atualizando texto do valor do Dial
    timerDial.onValueChanged: {
        timerDial.text = timerDialToText(timerDial.value)
    }
    // Atualização do texto do slider de número de pisques
    numblinksSlider.slider.onValueChanged: {
        var value = parseInt(numblinksSlider.slider.value)
        if (value === 0) numblinksSlider.label.text = "Pisques: Permanente"
        else if (value === 1) numblinksSlider.label.text = "Pisques: 1"
        else numblinksSlider.label.text = "Pisques: " + parseInt(value)
    }

    // Conversão dos ticks do dial para tempo em segundos
    function timerDialToSeconds(value){
        return value.toFixed(2)
    }
    // Conversão de tempo para texto para mostrar no Dial
    function timerDialToText(value){
        if (value === 0) return "PERM"
        else return "%1".arg(timerDialToSeconds(timerDial.value)) + " s"
    }

    function getRgbFromSliderPosition(position){
        if(position == 0) return 0;
        else if(position == 1/3) return 0.25 * 255;
        else if(position == 2/3) return 0.5 * 255;
        else return 255;
    }

    // Atualização do texto da porcentagem no slider
    function updateColorSliderText(slider_changed){
        if (slider_changed.value === 0) slider_changed.textItem.text = "0 %";
        else if (slider_changed.value === 1/3) slider_changed.textItem.text = "25 %";
        else if (slider_changed.value === 2/3) slider_changed.textItem.text = "50 %";
        else if (slider_changed.value === 1) slider_changed.textItem.text = "100 %";
        //colorSliderText.text = "eitcha"
    }
}
