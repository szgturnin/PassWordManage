import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
Rectangle{
    radius: 4
    width: 190
    height: 28
    color: "#ea0d5e"

    signal sigStyleBtnClick();

    Button{
        objectName: "styleBtnObjName"
        anchors.fill: parent
        RowLayout{
            anchors.centerIn: parent
            Image {
                id: img
                source: "qrc:/image/safe.png"
            }
            Text {
                id: loginText
                text: qsTr("安全登录")
                styleColor: "#c84017"
                font.pixelSize: 12
            }
        }
        onClicked: {
            sigStyleBtnClick();
            //mainWindow_stackView
        }
    }
}
