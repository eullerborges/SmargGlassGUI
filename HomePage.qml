import QtQuick 2.7

HomePageForm {
    led1Button.onChosen: {
        tabBar.currentIndex = 1;
        this.chosenLed = led1Button
    }
    led2Button.onChosen: {
        tabBar.currentIndex = 1;
        this.chosenLed = led2Button
    }
}
