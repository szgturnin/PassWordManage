import QtQuick 2.0

Rectangle{
    width: 50
    height: 50
    color: "green"
    radius: 25
    id:test
    Text {
        id: name
        text: qsTr("点击")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
