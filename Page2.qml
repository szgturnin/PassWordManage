import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
Page{
    id:page2
    property alias rectangle: rectangle
    function createModel( modeltxt)
    {
        testModel.append({
                                testText:modeltxt
                                })
    }
    function worked()
    {
        console.log("workd");
    }

    Connections{
        target:page3
        onSendListView:{
            //由于不熟练，上面的槽函数没有添加":",之前是这样写的  槽函数{}  于是这样就出现了一些我
            //无法解决的报错问题，也识别不了相关的一些函数，之后  槽函数:{}问题就全搞定了
            //createModel(accountDetails);
           // page2.worked:
            createModel(accountDetails);
           // myListView.currentIndex:

        }
    }



    Rectangle
    {
        id: rectangle
        radius: 8
        anchors.left: parent.left
        anchors.top: parent.top
        height: page2.height/10
        width: page2.width/5
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
             height: page2.height/10
            width: page2.width/5
            onClicked: {
                mystackview.push(page3);
            }
        }

    Rectangle
    {
        Component.onCompleted: {
            var rowNum=xml.howManyRows();
            var m_account="";
            var times=0;
            for(var i=1;i<=rowNum;i++)
            {
                if(times==0)
                {
                    m_account+=xml.getStringByNum(i)+":";
                    times++;
                }
                else if(times==1)
                {
                    m_account+=xml.getStringByNum(i)+"+";
                    times++;
                }
                else
                {
                    m_account+=xml.getStringByNum(i);
                    times=0;
                    testModel.append({
                                            testText:m_account
                                  //这个testText是不会自动提示的，但是能被QML识别出来
                                            })

                    m_account="";
                }
            }
        }

        id:window
        width: page2.width
        height: page2.height/10*9
        anchors.top: createButton.bottom
        ListModel {
            id: testModel
        }
        ListView
        {


            highlightFollowsCurrentItem: true
            anchors.fill: window
            id:myListView
            model: testModel


            spacing: 5
            delegate: SliderModel
                        {
                            id:itemModel
                            width: page2.width
                            height: page2.height/10
                           /* Rectangle{
                                width:100
                                height: 40
                                //color:testMouseArea.pressed ? "blue":"pink"
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.left: parent.left
                                anchors.leftMargin: 9
                                    Text {
                                    id:show
                                    anchors.centerIn: parent
                                    text: testText
                                }

                                MouseArea{
                                    id:testMouseArea
                                    anchors.fill: parent
                                }
                            }*/
                            Text {
                                id: show
                                text: testText
                                anchors.centerIn: parent
                                font.pixelSize: 27
                            }
                            onContentRectangleClicked:{
                                console.log("contentRectangleClicked")
                            }
                            onDeleteButtonClicked:{
                                testModel.remove(index)
                            }
                         }
            /*delegate: SliderModel
            {
                id:itemModel
                width: page2.width
                height: page2.height/10
                Rectangle
                {
                    border.color: "black"
                    border.width: 2
                    anchors.fill: parent
                    color: mousearea.pressed? "blue":"gold"
                    anchors.verticalCenter: parent.verticalCenter
                    Text {
                        anchors{
                            verticalCenter: parent.verticalCenter
                            horizontalCenter: parent.horizontalCenter
                        }

                        id: listmodelText
                        text: modelText
                        font.pixelSize:20
                    }
                }
                MouseArea
                {
                    id:mousearea
                    anchors.fill: parent

                  }
                onContentRectangleClicked:{
                    //todo something
                }
                onDeleteButtonShown:{
                    testModel.remove(index)
                }

             }*/
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
