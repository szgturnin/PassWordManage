import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Text {
        id: exercise
        text: UiBridge.getString();//这个字符串是由uibridge中传送过来的，绑定过程在main.cpp中
        anchors.centerIn: parent
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            UiBridge.revMessageFromQml("qml send message to c++");
        }
    }
}
