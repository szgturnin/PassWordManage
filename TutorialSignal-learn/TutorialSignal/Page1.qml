import QtQuick 2.0
import QtQuick.Controls 2.2
Page{
    Button{
        id:button1
        /*Text {
            id: text
            text: qsTr("open Page2")
            color: "yellow"
            anchors.left: page1.left
            anchors.right: page1.right
            anchors.top: page1.top
        }*/
        text:"open Page2"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top:parent.top


        onClicked: {
            mystackview.push(page2);
        }
    }
    Text {
        id: mytext
        anchors.top:button1.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom:parent.bottom
        font.bold: true
        font.pointSize:30
        text: qsTr("text")
    }
   Connections{
        target: page2
        onButtonClicked:{
            mytext.text=buttonId;
            mystackview.pop();
        }
    }
}
