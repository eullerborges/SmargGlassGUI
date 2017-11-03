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
        swipeView.currentIndex = 1
        swipeView.setCurrentIndex(1)
    }
}
