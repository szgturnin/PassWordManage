import QtQuick 2.0

Item {
    id:slider_model

    property int deleteButtonWidth: 100

    signal deleteButtonCanceled()
    signal deleteButtonClicked()
    signal deleteButtonHidden()
    signal deleteButtonPressed()
    signal deleteButtonReleased()
    signal deleteButtonShown()

    signal contentRectangleCanceled()
    signal contentRectangleClicked(var mouse)
    signal contentRectangleDoubleClicked(var mouse)
    signal contentRectangleEntered()
    signal contentRectangleExited()
    signal contentRectanglePositionChanged(var mouse)
    signal contentRectanglePressAndHold(var mouse)
    signal contentRectanglePressed(var mouse)
    signal contentRectangleReleased(var mouse)
    signal contentRectangleWheel(var wheel)

    property color deleteButtonPressedColor: "#80FF0000"
    property color deleteButtonColor: "#FF0000"
    Rectangle{
        id:deleteBtn
        width: deleteButtonWidth
        height: parent.height
        anchors.right: parent.right
        color: deleteButtonMouseArea.pressed ?
                   deleteButtonPressedColor  : deleteButtonColor
        Text {
            anchors.centerIn: parent
            color: "white"
            font.pixelSize: 14
            text: qsTr("Delete")
        }

        MouseArea{
            anchors.fill: parent
            onCanceled: {
                deleteButtonCanceled();
            }
            onClicked: {
                deleteButtonClicked();
            }
            onPressed: {
                deleteButtonPressed();
            }
            onReleased: {
                deleteButtonReleased();
            }
        }
    }

    Rectangle{
        id:contentRect
        width: parent.width
        height: parent.height
        color: contentMouseArea.pressed? "#ee1212" :"#37dd16"
        state: "hidden"
        states: [
            State {
                name: "hidden"
                PropertyChanges {
                    target: contentRect;
                    x:0
                }
            },
            State {
                name: "shown"
                PropertyChanges {
                    target: contentRect
                    x:0-deleteBtn.width
                }
            }
        ]

        onStateChanged: {
            if("hidden"==state){
                deleteButtonHidden();
            }
            else if("shown"==state){
                deleteButtonShown();
            }
        }

        transitions: Transition {
            NumberAnimation {
                properties: "x";
                duration: 200
            }
        }
        MouseArea{
            id:contentMouseArea
            anchors.fill: parent
            drag.target: contentRect
            drag.axis: Drag.XAxis
            drag.minimumX: -deleteBtn.width
            drag.maximumX: 20
            opacity: (600-contentMouseArea.x)/600 //随着拖动改变控件的透明度
            readonly property bool draging: drag.active
//            onDragChanged: {
//                console.log("onDragChanged")
//                if(!draging){
//                    if(contentRect.state=="hidden"){
//                        if(contentRect.x<(0-5)){
//                            contentRect.state="shown";
//                        }
//                        else{
//                            contentRect.state="hidden";
//                        }
//                    }
//                    else if(contentRect.state=="shown"){
//                        if(contentRect.x>(5-deleteBtn.width)){
//                            contentRect.state="hidden";
//                        }
//                        else{
//                            contentRect.state="shown";
//                        }
//                    }
//                }
//            }

            onCanceled: {
                contentRectangleCanceled();
            }
            onClicked: {
                contentRectangleClicked(mouse);
            }
            onDoubleClicked: {
                contentRectangleDoubleClicked(mouse);
            }
            onEntered: {
                contentRectangleEntered();
            }
            onExited: {
                contentRectangleExited();
            }
            onPositionChanged: {
                contentRectanglePositionChanged(mouse);
            }
            onPressAndHold: {
                contentRectanglePressAndHold(mouse);
            }
            onReleased: {
                contentRectangleReleased(mouse);
            }
            onWheel: {
                contentRectangleWheel(wheel);
            }
        }
    }


}
