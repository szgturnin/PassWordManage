#include "showmessage.h"
#include<QDebug>
ShowMessage::ShowMessage(QObject *parent) : QObject(parent)
{

}

void ShowMessage::displayMessage(QString message)
{
    qDebug()<<"show message form displayMessage::"<<message<<endl;
}
