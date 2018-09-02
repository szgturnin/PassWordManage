#include "uibridge.h"

UIBridge::UIBridge(QObject *parent) : QObject(parent)
{

}

QString UIBridge::getString() const
{
    return "string from getString() function";
}

void UIBridge::revMessageFromQml(QString message)
{
     qDebug()<<"Message form qml:"<<message<<endl;
     emit sendmessagetoShowMessage("inner c++Class send message to another c++Class in other different way");
}
