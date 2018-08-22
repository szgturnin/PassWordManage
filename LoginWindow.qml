import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
Rectangle{
    id:root
    radius: 4
    width: 195
    height: 60
    border.color: "#bdbdbd"
    border.width: 1
    ColumnLayout{
        spacing: 0
        TextField{
            id:account1
            placeholderText: qsTr("请输入账号")

            //signal accountChange(string name)
            background: Rectangle{
                implicitWidth: root.width
                implicitHeight: root.height/2
                opacity: 0 //为0 是看不见
            }
           // onTextChanged: account1.accountChange(account1.text)
        }
        Rectangle{
            width: root.width
            height: 1
            color: root.border.color
        }
        TextField{
            id:password1
           // signal passwordChange(string pwd)
            placeholderText: qsTr("请输入密码")
            echoMode: TextInput.Password
            background: Rectangle{
                implicitWidth: root.width//如果没有设置这个参数，会默认的按照其父级的大小参数
                implicitHeight: root.height/2
                opacity: 0
            }
           // onTextChanged: password1.passwordChange(password.text)
        }
    }
}
