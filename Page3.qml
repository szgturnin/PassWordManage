import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
Page{
    id:page3
    ColumnLayout{
        RowLayout{
            id:navigation
            width: page3.width
            height: page3.height/2
            Rectangle{
                radius: 8
                anchors.left: navigation.left
                anchors.top: navigation.top
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
            spacing: page3.width-160
            Button{
                id:createButton
                text: "保存"
                anchors.right: navigation.right
                anchors.top: navigation.top
                height: 50
                width: 80
            }
        }
        spacing: 5
        RowLayout
        {
            width: page3.width
            height: page3.height/2

            id:user
             Text {
                id: username
                text: qsTr("账号:")
                anchors.left: user.left
                anchors.top: user.top
                anchors.bottom: user.bottom
                width: page3.width/6
             }
         }
        RowLayout
        {
           width: page3.width
           height: page3.height/2
           id:passwd
           Text {
               id: passwdname
               text: qsTr("密码:")
               anchors.left: passwd.left
               anchors.top: passwd.top
               anchors.bottom: passwd.bottom
               width: page3.width/6
                }
         }


    }
}
