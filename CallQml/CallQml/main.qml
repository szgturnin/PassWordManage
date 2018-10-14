import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.1
//在这里给根元素起名为objectname  ,按钮起名为quitbutton，文本起名为textlabel  ,然后会在C++代码中用这些名字来查找对应的对象并改变他们
Window {
    objectName: "rootObject";
    visible: true
    width: 640
    height: 480
    //title: qsTr("Ni Cai wo zai na")
    Text {
        objectName: "textLable";
        text: qsTr("Hello World")
        anchors.centerIn: parent;
        font.pixelSize: 26
    }
    Button
    {
        anchors.right: parent.right
        anchors.rightMargin: 4
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4
        text:"quit"
        objectName: "quitButton"
    }
}
