import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property Page1 page1: Page1{ }
    property Page2 page2: Page2{}
    StackView{
        id:mystackview
        anchors.fill: parent
        initialItem: page1
    }
    Component.onCompleted: {
        page2.buttonClicked.connect(function(buttonId){console.log("xxxxxxxxx",buttonId)});
    }

    /*Component{
        id:page1
        Page1{

        }
    }
    Component{
        id:page2
        Page2{
            Component.onCompleted: {
                this.buttonClicked.connect(function(buttonId){});
            }
        }
    }*/
}
