import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
Rectangle {
    id:loginWindow
    radius: 16
    width: 640
    height: 480
    border.color:"#17bbb8"
    border.width: 1

    Image {
        id: backgroundImg
        source: "qrc:/image/yuzhibo.png"
        anchors.fill: parent
        opacity: 0.1
    }


    ColumnLayout{

        height: 40
        //anchors.centerIn: parent.Center
        anchors.horizontalCenter: parent.horizontalCenter

        anchors.verticalCenter: parent.verticalCenter
        id:columnLay

        TextField{
            id:account
            placeholderText: qsTr("请输入账号")

//            background: Rectangle{
//                implicitHeight: parent.height
//                implicitWidth: parent.width
//                opacity: 0.8  //为0是看不见
//            }
        }
        spacing: 1

        Rectangle{
            id:intervalRectangle
            height: 1
            width: parent.width
            color: loginWindow.color
        }

        TextField{
            id:passwd
            placeholderText: qsTr("请输入密码");
            echoMode: TextInput.Password

        }

        RowLayout{
            //anchors.horizontalCenter: parent.horizontalCenter

            CheckBox{
                id:passwdCheckBox
                text: qsTr("记住密码")
                width: columnLay.width/2
            }
            CheckBox{
                id:autoLogin
                text: qsTr("自动登录")
                width: columnLay.width/2
            }
        }

        StyleButton{
            id:loginBtn
            onSigStyleBtnClick: {
                mainWindow_stackView.push(createPage);
            }

        }

    }
}
