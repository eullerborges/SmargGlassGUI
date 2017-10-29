import QtQuick 2.4

LedButtonForm {
    id: button
    property string name
    property double leftMarginModifier: 0
    property double topMarginModifier: 0

    // Configurando parâmetros de posicionamento na imagem do óculos
    anchors.left: parent.left
    anchors.top: parent.top
    anchors.leftMargin: (parent.width - parent.paintedWidth)/2 + leftMarginModifier * parent.paintedWidth - width/2
    anchors.topMargin: (parent.height - parent.paintedHeight)/2 + topMarginModifier * parent.paintedHeight - height/2
    width: 16/640 * parent.paintedWidth
    height: width

    Component.onCompleted: {
        console.log(name + " X: " + anchors.leftMargin + " Y: " + anchors.topMargin)
    }

    //internalButton.onClicked: {chosen();}
    //define a scale animation
    Behavior on scale {
        NumberAnimation {
            duration: 100
            easing.type: Easing.InOutQuad
        }
    }
    //define transmission for the states
    transitions: [
        Transition {
            from: "*"; to: "Hovering"
            ColorAnimation { duration: 200 }
        },
        Transition {
            from: "*"; to: "Pressed"
            ColorAnimation { duration: 10 }
        }
    ]
    //Mouse area to react on click events
    MouseArea {
        hoverEnabled: true
        anchors.fill: button
        onEntered: {
            // Mudando a cor para uma cor desaturada no evento de Hover
            if (button.color != "#ffffff"){
                hoverColor = button.color;
                hoverColor.hslSaturation *= 0.7;
            }
            else hoverColor = "#aaaaaa"
            button.state='Hovering'
        }
        //onEntered: { var col = []; col[0] = button.color; col[0].hslSaturation *= 0.8; hoverColor = col[0]; button.state='Hovering'}
        onExited: { button.state=''}
        onClicked: { console.log("TRETA"); button.chosen(); button.clicked()}
        onPressed: { button.state="Pressed" }
        onReleased: {
            if (containsMouse)
              button.state="Hovering";
            else
              button.state="";
        }
    }
}
