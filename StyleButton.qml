import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
Rectangle {
    radius: 4
    width: 190
    height: 28
    color: "#00A3FF"

    signal testSig();//测试这个信号
    objectName: "rectangle"

    Button{
        objectName: "buttonObj"
        anchors.fill: parent
        RowLayout{
            anchors.centerIn: parent
            Image {
                id: name
                source: "qrc:/image/safe.png"
            }
            Text {
                id: text
                text: qsTr("安 全 登 录")
                color: "#fff"
                font.pixelSize: 12
            }
        }
        onClicked:{
            mystackview.push(page2);
            emit: testSig();//发送这个信号
            xml.createSig();
            xml.slotTest();

            xml.name="hello";
            //xml.setName("qml set name");
            console.log("StyleButton clicked");
        }
    }

    onTestSig: {
        console.log("StyleButton.qml 槽函数响应");//槽函数接收
    }

}
