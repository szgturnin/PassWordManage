import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQml 2.2
Window/*ApplicationWindow*/{
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    objectName: "windowObj"
    id:window

    ColumnLayout{
        id:lay
        anchors.fill: parent
        Kk{

             id:kk
             anchors.top:parent.top

        }

        Btn{
            anchors.top: kk.bottom
            id:btn
            function btnFunc(){
                console.log("btnFunc");
            }
        }

    }



    function laySlotFunc(){
        console.log("laySlotFunc")
    }

    Component.onCompleted:{

        kk.blick.connect(laySlotFunc);
        console.log("component is ready");
    }

    Connections{
        target: kk
        onBlick:btn.btnFunc();
    }


}
