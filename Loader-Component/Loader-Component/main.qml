import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    //title: qsTr("Hello World")
    Rectangle{
        width: 320
        height: 240
        color: "#c0c0c0"
        anchors.centerIn: parent
        Text {
            id: coloredText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top:parent.top
            anchors.topMargin: 4
           font.pixelSize: 32
            text: qsTr("hello world")
        }
    }

    Component
    {
        id:colorComponent
        Rectangle
        {
            id:colorPicker
            width:50
            height: 30
            signal colorPicked(color clr)
            MouseArea
            {
                anchors.fill: parent
                onPressed: colorPicker.colorPicked(colorPicker.color);
            }
        }
    }
    Loader
    {
        id:redLoader//可以对item重新进行布局
        width: 80;
        height: 60;
        anchors.left: parent.left;//这个parent.left的left虽然没有提示，但是实际运行说明还是生效的
        anchors.leftMargin: 4;
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4;
        sourceComponent: colorComponent
        onLoaded: {
            item.color="red";
        }
    }
    Loader
    {
        id:blueLoader//这里没有改变item的大小，所以item的大小还是原始值的大小
        anchors.left: redLoader.right
        anchors.leftMargin: 4
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4
        sourceComponent: colorComponent
        onLoaded: {
            item.color="blue"
        }
    }
    Connections{
        target: redLoader.item
        onColorPicked:{
            coloredText.color=clr;
        }
    }
    Connections{
        target: blueLoader.item
        onColorPicked:{
            coloredText.color=clr;
        }
    }
}
