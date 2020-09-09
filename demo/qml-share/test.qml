﻿import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
Rectangle {
    visible: true
    width: 640
    height: 480
    objectName: "windowObj1"
    id:window
    signal clicked()

    Text {
        id: btn1
        text: qsTr("btn1")
        anchors.fill: parent
    }

    MouseArea{
        onClicked: {
            clicked();
        }
        anchors.fill: parent
    }

    onClicked: {
        console.log("test.qml send sig ,this file onClicked")
    }

}
