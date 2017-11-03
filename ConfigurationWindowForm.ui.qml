import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item{
    property alias saveConfigButon: saveConfigButton
    property alias baudrateText: baudrate_textField.text
    property alias serialText: serialport_textField.text
    property alias footerPane: footerPane
    property alias popup: popup
    signal open
    signal serialConfigurationChanged
    Popup {
        //property alias dialogButtonBox: dialogButtonBox

        id: popup
        width: parent.width
        height: parent.height
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        modal: false
        focus: true
        padding: 1
        Pane{
            id: popupPage
            anchors.fill: parent
            //background: Rectangle{color: "red"}
            Column{
                id: formColumns
                property int num_form_columns: 3
                width: parent.width
                height: parent.height - footerPane.height - 5 - num_form_columns * spacing
                anchors.centerIn: parent
                spacing: 5
                Row{
                    width: parent.width
                    spacing: 10
                    property alias serialport_label: serialport_label
                    property alias serialport_textField: serialport_textField
                    Label{
                        id: serialport_label
                        anchors.verticalCenter: parent.verticalCenter
                        text: "Serial port: "
                        font.pixelSize: parent.height / 4
                    }

                    TextField{
                        id: serialport_textField
                        height: formColumns.height/formColumns.num_form_columns
                        width: parent.width - parent.serialport_label.width - parent.spacing
                        placeholderText: "Ex.: /dev/tty*"
                        font.pixelSize:  parent.height / 4
                        validator: RegExpValidator { regExp: /\/dev\/.*/ }
                    }
                }
                Row{
                    width: parent.width
                    spacing: 10
                    property alias baudrate_label: baudrate_label
                    property alias buadrate_textField: baudrate_textField
                    Label{
                        id: baudrate_label
                        anchors.verticalCenter: parent.verticalCenter
                        text: "Baudrate:  "
                        font.pixelSize: parent.height / 4
                    }

                    TextField{
                        id: baudrate_textField
                        height: formColumns.height/formColumns.num_form_columns
                        width: parent.width - parent.baudrate_label.width - parent.spacing
                        placeholderText: "Ex.: 115200"
                        font.pixelSize:  parent.height / 4
                        validator: IntValidator{bottom: 1200; top: 115200;}
                    }
                }
            }

            // Botão de salvar
            Pane{
                id: footerPane
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                //background: Rectangle{color: "yellow"}
                height: 0.15 * parent.height
                width: parent.width
                Button {
                    id: saveConfigButton
                    text: qsTr("Save Configuration")
                    height: parent.parent.height
                    width: 0.8 * parent.width
                    anchors.centerIn: parent
                    font.pixelSize: footerPane.height/3
                }
            }
        }
    }
}
