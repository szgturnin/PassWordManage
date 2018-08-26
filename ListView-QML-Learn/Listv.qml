import QtQuick 2.0

Rectangle {
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

    id:mainwindow
    Rectangle{

        id:window
        width: mainwindow.width
        height: mainwindow.height
        anchors.fill: mainwindow
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
