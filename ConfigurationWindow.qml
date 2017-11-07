import QtQuick 2.4

ConfigurationWindowForm {
    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    onOpen: popup.open()

    saveConfigButon.onClicked: {
        popup.close()
        //serialConfigurationChanged()
        backend.serialParamsChanged(serialText, baudrateText)
    }
}
