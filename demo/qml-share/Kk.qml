import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
Rectangle {
    visible: true
    width: 320
    height: 240
    objectName: "windowObj1"
    id:window
    signal blick()

    border.color: "green"


    Text {
        id: btn1
        text: qsTr("btn1")
        anchors.fill: parent
        color: "red"
    }

    MouseArea{
        onClicked: {
            blick();
        }
        anchors.fill: parent
    }

    onBlick: {
        console.log("test.qml send sig ,this file onClicked")
    }

}
