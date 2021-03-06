﻿import QtQuick 2.8
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import szg.test.customClassToQml 1.0
import QtQuick.Window 2.2
Window{
    visible: true
    width: 460
    height: 360
    property WrXml wrXml: null
    property Page1 page1: Page1{ }
    property Page2 page2: Page2{}
    property Page3 page3: Page3{}


    title: qsTr("PasswordManager")
    StackView{
        id:mystackview
        anchors.fill: parent
        initialItem: page1

    }

    function recvCPlusSig(){
        console.log("c++ sig connect");
    }
    function onNameChanged(){
        console.log("name changed");
        console.log(WrXml.ONE);
    }

    Component.onCompleted: {
        xml.sigCPlus.connect(recvCPlusSig)//C++信号连接到了qml的槽函数中
        xml.nameChanged.connect(onNameChanged)
    }
}
