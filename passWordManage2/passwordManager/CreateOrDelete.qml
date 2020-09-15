import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.1
Rectangle{
    id:createOrReturn

    Rectangle{
        radius: 16
        anchors.left: parent.left
        anchors.top: parent.top
        height: createOrReturn.height/10
        width: parent.width/5
        id:backRec
        color: backBtnArea.pressed? Qt.rgba(0.89,0.08,0.08,1):"#80999e"
        Text{
            id:backBtn
            text: qsTr("返回")
            font.pixelSize: 24
            anchors.centerIn: backRec
            MouseArea{
                id:backBtnArea
                anchors.fill: parent
                onClicked: {
                    mainWindow_stackView.pop();
                }
            }


        }
    }

    Rectangle{
        id:addBtn
        radius: 16
        color: addBtnArea.pressed? Qt.rgba(0.89,0.08,0.08,1):"#80999e"
        anchors.right: parent.right
        anchors.top: parent.top
        height: parent.height/10
        width: parent.width/5
        Text {
            text: qsTr("添加")
            anchors.centerIn: parent
            font.pixelSize: 24
            MouseArea{
                id:addBtnArea
                anchors.fill: parent
                onClicked: {
                    mainWindow_stackView.push(detailPage);
                }
            }
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

    function addASlider(group,key,value){
        var msg=group+"/"+key+"/"+value;
        list_model.append(
                    {
                        slider_text:msg
                    }
                    );
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
                width: m_listView.width
                id:slider_model
                height: m_listView.height/9
                Text {
                    text: slider_text
                    anchors.centerIn: parent
                    font.pixelSize: 27
                }
                onContentRectangleClicked: {
                    console.log("connect contentRectangleClicked")
                }
                onDeleteButtonClicked: {
                    console.log("remove index:",index,"text:",slider_text);
                    var list=slider_text.split("/");
                    console.log(list);
                    var group=list[0];
                    var key=list[1];
                    iniFile.remove(group,key);
                    list_model.remove(index);
                }
            }
        }
    }
}
