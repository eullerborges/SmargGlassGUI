import QtQuick 2.7

HomePageForm {
    id: homePage
    Component.onCompleted: {
        for (var i=0; i < ledButtons.length; i++){
            ledButtons[i].onChosen.connect(ledChosen)
        }
        connectionStatus = "Disconnected"
    }
    Connections {
        target: configurationWindow
        onSerialConfigurationChanged: {
            connectionStatus = "CHANGED!"
        }
    }
    // Tratando sinais de conexão da porta serial
    Connections {
        target: backend
        onSerialOpened: {
            console.debug("Serial opened signal!")
            connectionStatus = "Connected"
        }
    }
    // Tratando sinais de desconexão da porta serial
    Connections {
        target: backend
        onSerialClosed: {
            console.debug("Serial closed signal!")
            connectionStatus = "Disconnected"
        }
    }

    Connections {
        target: backend
        onLedColorChanged: {
            console.debug("RECVD LED " + number+ " CFG: " + color);
            //ledButtons[number].color = Qt.lighter(color, 1.5)
            var red_before = color.r;
            color.r = Math.min(Math.pow(0.7 * color.r, 1/6), 1);
            color.b = Math.min(Math.pow(color.b, 1/6), 1);
            color.g = Math.min(Math.pow(1.4*color.g, 1/6), 1);
            console.log("RED BEFORE: " + red_before + " RED AFTER: " + color.r)
            //console.debug("CHANGED LED " + number+ " CFG: " + color);
            ledButtons[number].color = color
        }
    }

    serialConfigButton.onClicked: {configurationWindow.open()}
    // Eventos de mudança do label de status da conexão
    onConnectionStatusChanged: {
        console.log("ConnectionStatusChanged! " + connectionStatus);
        infoPaneStatusLabel.text = connectionStatus;
        if (connectionStatus == "Disconnected") infoPaneStatusLabel.color = "red";
        if (connectionStatus == "Connected") infoPaneStatusLabel.color = "green";
    }

    // Função para tratamento do LED escolhido
    function ledChosen(chosen_led){
        homePage.chosenLed = chosen_led
        //swipeView.currentIndex = 1
        swipeView.setCurrentIndex(1)
    }
}
