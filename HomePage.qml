import QtQuick 2.7

HomePageForm {
//    button1.onClicked: {
//        console.log("Button Pressed. Entered text: " + textField1.text);
//    }
    led1Button.onChosen: {
        console.log("EITA");
        tabBar.currentIndex = 1;
        this.chosenLed = led1Button
    }
    led2Button.onChosen: {
        console.log("EITA");
        tabBar.currentIndex = 1;
        this.chosenLed = led2Button
    }
//    led1Button.onClicked:{
//        console.log("Foi demais no led1");
//    }
//    led2Button.onClicked:{
//        console.log("Foi demais no led2");
//        tabBar.currentIndex = 1;
//    }

}
