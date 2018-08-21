import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 560
    height: 900
    title: qsTr("PasswordManager")
    LoginWindow{
        id:loginwindow
    }
}
