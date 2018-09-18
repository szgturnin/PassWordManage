import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Page{
    id:page3
    ColumnLayout{

        RowLayout{
            id:navigation      
                Button{

                    font.pixelSize: 24
                    id:_return
                    text: "返回"

                    visible: true
                    onClicked: {
                        mystackview.pop();
                    }
                }

            spacing: page3.width-_return.width-createButton.width
            Button{
                id:createButton
                text: "保存"
                font.pixelSize: 24
                anchors.right: navigation.right
                anchors.top: navigation.top

            }
        }
        spacing: 5
        RowLayout
        {
            id:user
             Text {

                //width: page3.width/3

                id: username
                text: qsTr("账号:")
                font.pixelSize: 36
                anchors.left: user.left
             //  anchors.top: user.top
            //    anchors.bottom: user.bottom

             }
             /*TextInput{
                 color: "red"
                 anchors.left: username.right
                 //anchors.top: username.top
                // anchors.bottom: username.bottom
                // anchors.right: page3.right
                 font.pixelSize: 36
                 height: username.height*5
                 width: user.width-username.width
                 id:userinput
                 focus: true
                 KeyNavigation.tab: passwdinput
                 activeFocusOnPress: true
             }*/
             TextField{
                 id:userinput
                    font.pixelSize: 36
                 placeholderText: qsTr("请输入账号")
               //  echoMode: TextInput.Password
                 background: Rectangle{
                     implicitWidth: root.width//如果没有设置这个参数，会默认的按照其父级的大小参数
                     implicitHeight: root.height/2
                     opacity: 0
                 }

             }
         }
        RowLayout
        {

           id:passwd
           Text {
               id: passwdname
               text: qsTr("密码:")
               font.pixelSize: 36
               anchors.left: passwd.left
                }        
           TextField{
               id:passwdinput
                font.pixelSize: 36
               placeholderText: qsTr("请输入密码")
              echoMode: TextInput.Password
               background: Rectangle{
                   implicitWidth: root.width//如果没有设置这个参数，会默认的按照其父级的大小参数
                   implicitHeight: root.height/2
                   opacity: 0
               }

           }
         }


    }
}
