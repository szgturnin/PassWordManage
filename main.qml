import QtQuick 2.8
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
ApplicationWindow {
    visible: true
    width: 460
    height: 360
    title: qsTr("PasswordManager")

    Rectangle{
       id:_mainwindow
       anchors.fill: parent
       ColumnLayout{
           id:layout
           anchors.horizontalCenter: _mainwindow.horizontalCenter
           anchors.verticalCenter: _mainwindow.verticalCenter

           LoginWindow{
               id:loginwindow
           }
           RowLayout{
               anchors.horizontalCenterOffset: layout.horizontalCenter
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
               anchors.horizontalCenter: layout.horizontalCenter

           }
       }

    }



}
