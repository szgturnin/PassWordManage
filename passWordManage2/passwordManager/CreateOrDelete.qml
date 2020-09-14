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
            mainWindow_stackView.push(detailPage);
        }
    }

    Component.onCompleted: {
        var list=iniFile.getAllData();
        for(var i in list){
            console.log(list[i]);
            list_model.append(
                        {
                            slider_text:list[i]
                        }
                        );
//            var msgs=list[i].split("/");
//            var group=msgs[0];
//            var key=msgs[1];
//            var value=msgs[2];

        }

    }

    Rectangle{
        id:showList
        width: parent.width
        height: parent.height/10*9
        anchors.top: addBtn.bottom

        ListModel{
            id:list_model
        }

        ListView{
            highlightFollowsCurrentItem: true
            anchors.fill: showList
            id:m_listView
            model: list_model

            spacing: 5

            delegate:SliderModel{
                width: parent.width
                id:slider_model
                height: parent.height/9
                Text {
                    text: slider_text
                    anchors.centerIn: parent
                    font.pixelSize: 27
                }
                onContentRectangleClicked: {
                    console.log("connect contentRectangleClicked")
                }
                onDeleteButtonClicked: {
                    m_listView.remove(index);

                }
            }
        }
    }
}
