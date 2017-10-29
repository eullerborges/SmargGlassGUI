import QtQuick 2.7

HomePageForm {
    id: homePage
    Component.onCompleted: {
        for (var i=0; i < ledButtons.length; i++){
            ledButtons[i].onChosen.connect(ledChosen)
        }
    }

    led1Button.onChosen: {
        tabBar.currentIndex = 1;
        this.chosenLed = led1Button
    }
    led2Button.onChosen: {
        tabBar.currentIndex = 1;
        this.chosenLed = led2Button
    }

    function ledChosen(chosen_led){
        console.log("OIA: " + chosen_led.name)
        homePage.chosenLed = chosen_led
        tabBar.currentIndex = 1
    }
}
