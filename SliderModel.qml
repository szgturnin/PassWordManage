import QtQuick 2.0

Item {
    id: container
    //width: parent.width
    //height: parent.height/10

    // public:

    property alias contentRectangleAcceptedButtons: contentMouseArea.acceptedButtons
    property color contentRectangleColor: "gold"
    property alias contentRectangleContainsMouse: contentMouseArea.containsMouse
    property alias contentRectangleCursorShape: contentMouseArea.cursorShape
    property alias contentRectangleEnabled: contentRect.enabled
    property alias contentRectangleHoverEnabled: contentMouseArea.hoverEnabled
    property alias contentRectangleMouseX: contentMouseArea.mouseX
    property alias contentRectangleMouseY: contentMouseArea.mouseY
    property alias contentRectangleIsPressed: contentMouseArea.pressed
    property alias contentRectanglePressedButtons: contentMouseArea.pressedButtons
    property color contentRectanglePressedColor: "pink"
    property alias contentRectanglePreventStealing: contentMouseArea.preventStealing
    property alias contentRectanglePropagateComposedEvents: contentMouseArea.propagateComposedEvents

    property alias deleteButtonAcceptedButtons: deleteButtonMouseArea.acceptedButtons
    property color deleteButtonColor: "#FF0000"
    property alias deleteButtonContainsMouse: deleteButtonMouseArea.containsMouse
    property alias deleteButtonCursorShape: deleteButtonMouseArea.cursorShape
    property alias deleteButtonEnabled: deleteButtonMouseArea.enabled
    property alias deleteButtonHoverEnabled: deleteButtonMouseArea.hoverEnabled
    property alias deleteButtonMouseX: deleteButtonMouseArea.mouseX
    property alias deleteButtonMouseY: deleteButtonMouseArea.mouseY
    property alias deleteButtonIsPressed: deleteButtonMouseArea.pressed
    property alias deleteButtonPressedButtons: deleteButtonMouseArea.pressedButtons
    property color deleteButtonPressedColor: "#80FF0000"
    property alias deleteButtonPreventStealing: deleteButtonMouseArea.preventStealing
    property alias deleteButtonPropagateComposedEvents: deleteButtonMouseArea.propagateComposedEvents
    property int deleteButtonWidth: 100

    property int hideOrShowAnimationDuration: 200
    property int slidingDistanceTriggerChangeState: 5

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

    function hideDeleteButton(withAnimation) {
        if (withAnimation) {
            contentRect.state = "hidden"
        } else {
            contentRect.x = 0
        }
    }

    function showDeleteButton(withAnimation) {
        if (withAnimation) {
            contentRect.state = "shown"
        } else {
            contentRect.x = 0 - deleteButton.width
        }
    }

    // private:

    onContentRectangleClicked: {
        if (ListView.view !== null)
        {//这个信号是由Listview中的model发出来的，ListView,可能指的就是包含这个view的父
            ListView.view.currentItem.hideDeleteButton(true)
            ListView.view.currentIndex = index
        }
    }

    onDeleteButtonShown: {
        if (ListView.view !== null) {
            if (ListView.view.currentItem !== null) {
                ListView.view.currentItem.hideDeleteButton(true)
            }
            ListView.view.currentIndex = index
        }
    }

    Rectangle {
        id: deleteButton
        width: parent.deleteButtonWidth
        height: parent.height
        color: deleteButtonMouseArea.pressed ?
                   deleteButtonPressedColor  : deleteButtonColor
        anchors.right: parent.right
        opacity: Math.max((0 - contentRect.x) / deleteButton.width, 0.4)


        Text {
            text: qsTr("DELETE")
            anchors.centerIn: parent
            color: "white"
            font.pointSize: 14
        }

        MouseArea {
            id: deleteButtonMouseArea
            anchors.fill: parent
            onCanceled: {
                deleteButtonCanceled()
            }
            onClicked: {
                deleteButtonClicked()
            }
            onPressed: {
                deleteButtonPressed()
            }
            onReleased: {
                deleteButtonReleased()
            }
        }
    }

    Rectangle {
        id: contentRect
        width: parent.width
        height: parent.height
        color: contentMouseArea.pressed ? contentRectanglePressedColor
                                        : contentRectangleColor
        state: "hidden"

        onStateChanged: {
            if ("hidden" == state) {
                deleteButtonHidden()
            } else if ("shown" == state) {
                deleteButtonShown()
            }
        }

        states: [
            State {
                name: "hidden"
                PropertyChanges { target: contentRect; x: 0 }
            },State {
                name: "shown"
                PropertyChanges { target: contentRect; x: 0 - deleteButton.width }
            }
        ]

        transitions: Transition {
            NumberAnimation { properties: "x"; duration: hideOrShowAnimationDuration }
        }

        MouseArea {
            id: contentMouseArea
            anchors.fill: parent
            drag.target: contentRect
            drag.axis: Drag.XAxis
            drag.minimumX: - deleteButton.width
            drag.maximumX: 10
            opacity: (600-contentMouseArea.x)/600//随着拖动改变控件的透明度
            readonly property bool draging: drag.active
            onDragingChanged:
            {
                if (!draging)
                {
                    if (contentRect.state == "hidden")
                    {
                        if (contentRect.x < (0-slidingDistanceTriggerChangeState)) {
                            contentRect.state = "shown"
                        } else {
                            contentRect.state = ""
                            contentRect.state = "hidden"
                        }
                    }
                    else if (contentRect.state == "shown")
                    {
                        if (contentRect.x >
                                (slidingDistanceTriggerChangeState - deleteButton.width)) {
                            contentRect.state = "hidden"
                        } else {
                            contentRect.state = ""
                            contentRect.state = "shown"
                        }
                    }
                }
            }

            onCanceled: {
                contentRectangleCanceled()
            }
            onClicked: {
                contentRectangleClicked(mouse)
            }
            onDoubleClicked: {
                contentRectangleDoubleClicked(mouse)
            }
            onEntered: {
                contentRectangleEntered()
            }
            onExited: {
                contentRectangleExited()
            }
            onPositionChanged: {
                contentRectanglePositionChanged(mouse)
            }
            onPressAndHold: {
                contentRectanglePressAndHold(mouse)
            }
            onReleased: {
                contentRectangleReleased(mouse)
            }
            onWheel: {
                contentRectangleWheel(wheel)
            }
        }
    }

    // private:
    default property alias __content: contentMouseArea.data

}
