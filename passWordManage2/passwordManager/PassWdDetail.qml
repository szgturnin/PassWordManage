import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtQuick.Window 2.1
Rectangle{
    id:passWdDetail_id

    ColumnLayout{
        id:vLay



        RowLayout{
            id:hLay
            Button{
                font.pixelSize: 24
                id:returnBtn
                visible: true
                text: qsTr("返回")
                onClicked: {
                    mainWindow_stackView.pop();
                }
            }
            spacing: passWdDetail_id.width-returnBtn.width-createBtn.width
            Button{
                id:createBtn
                text: qsTr("保存")
                font.pixelSize: 24
                anchors.right: hLay.right
                anchors.top: hLay.top

                onClicked: {
                    iniFile.write(whereAccount.text,inputAccount.text,passWd.text);//注册的对象直接调用
                    createPage.addASlider(whereAccount.text,inputAccount.text,passWd.text);
                    whereAccount.text="";
                    inputAccount.text="";
                    passWd.text="";
                    mainWindow_stackView.pop();
                }
            }
        }

        spacing: 5

        RowLayout{
            id:whereAccount_HLay
            Text {
                text: qsTr("什么平台的账号:")
                font.pixelSize: 28
                anchors.left: whereAccount_HLay.left
            }
            TextField{
                id: whereAccount
                font.pixelSize: 28
                placeholderText: qsTr("请输入你的账户归属")
            }
        }

        RowLayout{
            id:inputAccount_HLay
            Text {
                text: qsTr("账号:");
                font.pixelSize: 36
                anchors.left: inputAccount_HLay.left
            }
            TextField{
                id: inputAccount
                font.pixelSize: 36
                placeholderText: qsTr("请输入你的账户")
            }
        }

        RowLayout{
            id:passWd_HLay
            Text {
                text: qsTr("密码:")
                font.pixelSize: 36
                anchors.left: passWd_HLay.left
            }
            TextField{
                id: passWd
                font.pixelSize: 36
                placeholderText: qsTr("请输入你的密码")
                echoMode: TextInput.Password
            }
        }

    }
}
