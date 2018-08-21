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
                implicitHeight: root.height/2 //此时用width 和height 输入有问题？？？
                opacity: 0 //为0 是看不见
            }
           // onTextChanged: account1.accountChange(account1.text)
        }
    }
}
