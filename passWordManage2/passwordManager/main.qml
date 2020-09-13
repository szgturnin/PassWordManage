import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("PasswordManager")

    property LoginWindow lginWindow: LoginWindow{}  //实例化LoginWindow对象给别名 lginWindow


    StackView{
        id:mainWindow_stackView
        anchors.fill: parent
        initialItem: lginWindow
    }

//    LoginWindow{
//        anchors.fill: parent
//    }


}
