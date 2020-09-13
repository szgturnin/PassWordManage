import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.1
Rectangle{
    id:createOrReturn

    Rectangle{
        radius: 8
        anchors.left: parent.left
        anchors.top: parent.top
        height: createOrReturn.height/10
        width: parent.width/5
        Button{
            id:backBtn
            text: qsTr("返回")
            anchors.fill: parent
            visible: true
            onClicked: {
                mainWindow_stackView.pop();
            }
        }
    }

    Button{
        id:addBtn
        text: qsTr("添加")
        anchors.right: parent.right
        anchors.top: parent.top
        height: parent.height/10
        width: parent.width/5
        onClicked: {
            //mainWindow_stackView
        }
    }

    Component.onCompleted: {
        var list=iniFile.getAllData();
        console.log(list)

    }

    Rectangle{
        id:showList
        width: parent.width
        height: parent.height/10*9
        anchors.top: addBtn.bottom

    }
}
