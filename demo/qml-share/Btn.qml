import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
Item {
    Text {
        id: name
        text: qsTr("Btn")
        anchors.fill: parent
        color: "black"
        font.pixelSize: 18
    }
    signal btnClick();
    MouseArea{
        anchors.fill: parent
        onClicked: {
            btnClick();
        }
    }

    width: 320
    height: 240

}
