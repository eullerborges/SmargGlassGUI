import QtQuick 2.7

HomePageForm {
    id: homePage
    Component.onCompleted: {
        for (var i=0; i < ledButtons.length; i++){
            ledButtons[i].onChosen.connect(ledChosen)
        }
    }
    function ledChosen(chosen_led){
        console.log("OIA: " + chosen_led.name)
        homePage.chosenLed = chosen_led
        swipeView.currentIndex = 1
        swipeView.setCurrentIndex(1)
    }
}
