import QtQuick 2.4

LedButtonForm {
    id: button
    //onPressed: {console.log("AIAIAI")}
    internalButton.onClicked: {chosen();}
    //button.button.onClicked: {console.log("AIAIAI")}
    //define a scale animation
//    Behavior on scale {
//        NumberAnimation {
//            duration: 100
//            easing.type: Easing.InOutQuad
//        }
//    }
//    //define transmission for the states
//    transitions: [
//        Transition {
//            from: "*"; to: "Hovering"
//            ColorAnimation { duration: 200 }
//        },
//        Transition {
//            from: "*"; to: "Pressed"
//            ColorAnimation { duration: 10 }
//        }
//    ]
//    //Mouse area to react on click events
//    MouseArea {
//        hoverEnabled: true
//        anchors.fill: button
//        onEntered: { button.state='Hovering'}
//        onExited: { button.state=''}
//        onClicked: { console.log("TRETA"); button.clickedd();}
//        onPressed: { button.clickedd(); }
//        onReleased: {
//            if (containsMouse)
//              button.state="Hovering";
//            else
//              button.state="";
//        }
//    }
}
