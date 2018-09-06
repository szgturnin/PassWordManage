import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
Page{
    id:page2

    Rectangle{
        radius: 8
        anchors.left: parent.left
        anchors.top: parent.top
        height: 50
        width: 80
        Button{
            id:_return
            text: "返回"
            anchors.fill: parent
            visible: true
            onClicked: {
                mystackview.pop();
            }
        }
    }
    Button{
        id:createButton
        text: "添加"
        anchors.right: parent.right
        anchors.top: parent.top
        height: 50
        width: 80
        onClicked: {
            mystackview.push(page3);
        }
    }

}
