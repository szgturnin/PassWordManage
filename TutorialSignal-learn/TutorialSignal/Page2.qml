import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
Page{
     signal buttonClicked(var buttonId)//这就声明了一个信号在QML里面
      ColumnLayout{
          anchors.fill: parent
          id:mybuttons
          spacing: 5

          Button{
              id:button1
              Layout.fillWidth: true
              Layout.fillHeight: true
              text:"Option 1"
          }
          Button{
              id:button2
              Layout.fillWidth: true
               Layout.fillHeight: true
              text:"Option 2"
          }
          Button{
              id:button3
              Layout.fillWidth: true
               Layout.fillHeight: true
              text:"Option 3"
          }
          Button{
              id:button4
              Layout.fillWidth: true
               Layout.fillHeight: true
              text:"Option 4"
          }
          Button{
              id:button5
              Layout.fillWidth: true
               Layout.fillHeight: true
              text:"Option 5"
          }   
      }
      /*Connections{//这里就类似qt widget里面的connection了
          target: button1
          onClicked:{
              buttonClicked(1);
          }
      }
      Connections{
          target: button2
          onClicked:{
              buttonClicked(2);
          }
      }
      Connections{
          target: button3
          onClicked:{
              buttonClicked(3);
          }
      }
      Connections{
          target: button4
          onClicked:{
              buttonClicked(4);
          }//发送信号
      }
      Connections{
          target: button5
          onClicked:{
              buttonClicked(5);
          }
      }*/
      //把上面5个Connections放在一起的写法是：
      Component.onCompleted: {
          button1.clicked.connect(function(){
          buttonClicked(1);
          });
          button2.clicked.connect(function(){
          buttonClicked(2);
          });
          button3.clicked.connect(function(){
          buttonClicked(3);
          });
          button4.clicked.connect(function(){
          buttonClicked(4);
          });
          button5.clicked.connect(function(){
          buttonClicked(5);
          });
      }
}
