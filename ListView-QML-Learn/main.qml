import QtQuick 2.9
import QtQuick.Window 2.11
import QtQuick.Controls 2.2
ApplicationWindow{
    width: 500
    height: 500
    visible:true
    id:mainwindow
    title: qsTr("Listview")
    Testcircle{
        width: mainwindow.width
        anchors.top: parent.header
        height: parent.height/10
        id:one
        MouseArea{

            onClicked: {

            }
        }
    }



    Rectangle{
        Component.onCompleted: {
            var color=["orange","green","yellow","cyan","blue"];
            var j=0;
            var tempcolor="black";
            for(var i=0;i<10;i++)
            {
                if(j===color.length)
                {
                    j=0;
                }
                if(color[j]==="blue"||color[j]==="green")
                {
                    tempcolor="white";
                }
                else{
                    tempcolor="black";
                }
               mylistview.model.append({
                                       modelText:"Yes"+i,
                                       windowcolor:color[j],
                                       modelColor:tempcolor
                                       })
                j++;
            }

        }
        id:window
        width: mainwindow.width
        height: mainwindow.height/10*9
        anchors.top:one.bottom
        ListView
        {

            anchors.fill: window
            id:mylistview
            model: ListModel{}
            spacing:5
            delegate: Rectangle{
                color: windowcolor
                border.color: "black"
                border.width: 5
                width: mainwindow.width
                height: mainwindow.height/10
                Text {
                    anchors{
                        verticalCenter: parent.verticalCenter
                        horizontalCenter: parent.horizontalCenter
                    }
                    color: modelColor
                    font.pointSize: 24
                    text:modelText
                }
            }
        }
    }
}
