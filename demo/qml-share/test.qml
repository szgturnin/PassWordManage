import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
Rectangle {
    visible: true
    width: 640
    height: 480
    objectName: "windowObj1"
    id:window


    ColumnLayout{
        anchors.fill: parent
        Button{
            objectName: "btn"
            anchors.bottom: parent.bottom
            text: "btn"
            function testSig(){
                console.log("test metaObject");
            }

        }

    }



}
