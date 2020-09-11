import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
Rectangle {
    id:item
    visible: true
    width: 320
    height: 240
    Text {
        id: name
        text: qsTr("Btn")
        anchors.fill: parent
        color: "black"
        font.pixelSize: 18
    }
    border.color: "green"
    signal btnClick();
    MouseArea{
        anchors.fill: parent
        onClicked: {
            btnClick();
        }
    }

    function bbtnClick(){
        console.log("bbtnClick")
    }

    Component.onCompleted:{
        btnClick.connect(bbtnClick);
    }
    onBtnClick:{
        console.log("onBtnClick");
    }
}
