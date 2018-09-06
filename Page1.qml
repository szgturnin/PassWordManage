import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
Rectangle{

   id:_mainwindow
   Image {
       id: mainbackground
       source: "qrc:/image/yuzhibo.png"
       anchors.fill: _mainwindow
   }
   anchors.fill: parent
       ColumnLayout{
           id:layout1
           anchors.horizontalCenter: _mainwindow.horizontalCenter
           anchors.verticalCenter: _mainwindow.verticalCenter

           LoginWindow{
               id:loginwindow
           }
           RowLayout{
               anchors.horizontalCenter: layout1.horizontalCenter
               CheckBox{
                   id:passwordBox
                   text:qsTr("记住密码")
               }
               CheckBox{
                   id:autologin
                   text:qsTr("自动登录")
               }
           }
           StyleButton{
               id:_button
               anchors.horizontalCenter: layout1.horizontalCenter

           }
       }

   }
