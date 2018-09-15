import QtQuick 2.11
import QtQuick.Window 2.11
import QmlAndCplusClass 1.0
import QtQuick.Controls 2.2
ApplicationWindow
{
    visible: true
    width: 800
    height: 600
    Rectangle
    {
        width: 360
        height: 360
        Text {
            id: timeLable
            anchors.left: parent.left
            anchors.leftMargin: 4
            anchors.top:parent.top
            anchors.topMargin: 4
            font.pixelSize: 26

            text: qsTr("wo shishui")
        }
        ColorMaker
        {
            id:colorMaker
            color:Qt.green
        }
        Rectangle
        {
            id:colorRect
            anchors.centerIn: parent
            width: 200;
            height: 200
            color: "blue"
            Text {
                id: test
                text: qsTr("wozainaline ")
            }
        }
        Button
        {
            id:start
            text:"start"
            anchors.left: parent.left
            anchors.leftMargin: 4
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 4
            onClicked: {
                colorMaker.start();
            }
        }
        Button
        {
            id:stop
            text: "stop"
            anchors.left: start.right
            anchors.bottom: start.bottom
            anchors.leftMargin: 4
            onClicked: {
                colorMaker.stop();
                tee();
            }
        }
        function changeAlgorithm(button,algorithm)
        {
            switch(algorithm)
            {
            case 0:
                button.text="RandomRGB";
                break;
            case 1:
                 button.text="RandomRed";
                break;
            case 2:
                button.text="RandomGreen";
                break;
            case 3:
                button.text="RandomBlue";
                break;
            case 4:
                button.text="LinearIncrease";
                break;
            }
        }
        Button
        {
            id:colorAlgorithm
            text:"RandomRGB"
            anchors.left: stop.right
            anchors.leftMargin: 4
            anchors.bottom: start.bottom
            onClicked: {
                var algorithm=(colorMaker.algorithm()+1)%5;
                parent.changeAlgorithm(colorAlgorithm,algorithm);
                colorMaker.setAlgorithm(algorithm);
            }
        }
        Button
        {
            id:quit
            text: "quit"
            anchors.left: colorAlgorithm.right
            anchors.leftMargin: 4
            anchors.bottom: start.bottom
            onClicked: {
                Qt.quit();
            }
        }

        Component.onCompleted: {
            colorMaker.color=Qt.rgba(0,180,120,255);
            colorMaker.setAlgorithm(ColorMaker.LinearIncrease);
            changeAlgorithm(colorAlgorithm,colorMaker.algorithm());
        }
        Connections{
            target: colorMaker
            onCurrentTime:{
                timeLable.text=strTime;
                timeLable.color=colorMaker.timeColor;
            }
        }
        Connections{
            target: colorMaker
            onColorChanged:{
                colorRect.color=color;
            }
        }
    }
    function tee()//如果函数定义调不通，那么更改函数定义的作用域，或者是使用父类的ID去调用，都是可以解决这个问题的。
    {
        console.log("yes it works");
    }
}

