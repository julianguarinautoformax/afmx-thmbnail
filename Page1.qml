import QtQuick 2.7
import afmx.ui.thmb 1.0



Page1Form {
    button1.onClicked: {
        console.log("Button Pressed. Entered text: " + textField1.text);
    }
    
    Rectangle {
        anchors.fill:parent
        border.color: "Blue"
        AfmxThmbImg{
            id:thmb
            anchors.fill:parent
            
        }
        Component.onCompleted: {
            thmb.setThmb(manager.getThmbContainer("/Users/julianguarin2010/Code/hack/Afmx/afmx-imagelist/resources/png/prohibition.png"));
        }
    }
    
}
