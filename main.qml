import QtQuick 2.8
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
ApplicationWindow {
    visible: true
    width: 460
    height: 360
    property Page1 page1: Page1{ }
    property Page2 page2: Page2{}
    property Page3 page3: Page3{}
    title: qsTr("PasswordManager")
    StackView{
        id:mystackview
        anchors.fill: parent
        initialItem: page1
    }

}
