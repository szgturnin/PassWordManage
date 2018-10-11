#include "wrxml.h"

WrXml::WrXml(QObject *parent) : QObject(parent)
{

}

void WrXml::ChangeXml(QString username, QString passwd)
{
    QFile file(QDir::currentPath()+QString("/test.xml"));
    if(!file.open(QFile::Text|QFile::ReadOnly|QIODevice::WriteOnly))
    {
        qDebug()<<"open file is fail"<<endl;
        return;
     }
    QDomDocument doc;
    if(!doc.setContent(&file))//把FILE文件中的文本读取到doc中
    {
        file.close();
        return ;
    }
    QDomDocument Xml;
    QDomElement rootElem=doc.documentElement();
    QDomElement main=  Xml.createElement(rootElem.tagName());
    Xml.appendChild(main);
    QDomNode rootNode=rootElem.firstChild();
    int flag=0;
    while (!rootNode.isNull())
    {
        QDomElement fileElem=rootNode.toElement();
        if(!fileElem.isNull())
        {
            if(fileElem.tagName()==username)
            {
                flag=1;
                QDomElement newnode=doc.createElement(fileElem.tagName());
                main.appendChild(newnode);
                QDomText text=doc.createTextNode(passwd);
                newnode.appendChild(text);
            }
            else
            {
                QDomElement newnode=doc.createElement(fileElem.tagName());
                main.appendChild(newnode);
                QDomText text=doc.createTextNode(fileElem.text());
                newnode.appendChild(text);
            }
        }
        rootNode=rootNode.nextSibling();
    }
    if(flag==0)
    {
        QDomElement tagname=doc.createElement(username);
        main.appendChild(tagname);
        QDomText text=doc.createTextNode(passwd);
        tagname.appendChild(text);
        qDebug()<<Xml.toString()<<endl;
    }
    file.resize(0);
    QTextStream textOutput(&file);
    textOutput<<Xml.toString();
    file.close();
}

void WrXml::DeleteXml(QString username, QString passwd)
{
    QFile file(QDir::currentPath()+QString("/test.xml"));
    if(!file.open(QFile::Text|QFile::ReadOnly|QIODevice::WriteOnly))
    {
        qDebug()<<"open file is fail"<<endl;
        return;
     }
    QDomDocument doc;
    if(!doc.setContent(&file))//把FILE文件中的文本读取到doc中
    {
        file.close();
        return ;
    }
    QDomDocument Xml;
    QDomElement rootElem=doc.documentElement();
    QDomElement main=  Xml.createElement(rootElem.tagName());
    Xml.appendChild(main);
    QDomNode rootNode=rootElem.firstChild();
    int flag=0;
    while (!rootNode.isNull())
    {
        QDomElement fileElem=rootNode.toElement();
        if(!fileElem.isNull())
        {
            if(fileElem.tagName()==username)
            {
                flag=1;

            }
            else
            {
                QDomElement newnode=doc.createElement(fileElem.tagName());
                main.appendChild(newnode);
                QDomText text=doc.createTextNode(fileElem.text());
                newnode.appendChild(text);
            }
        }
        rootNode=rootNode.nextSibling();
    }
    if(flag==0)
    {
        QDomElement tagname=doc.createElement(username);
        main.appendChild(tagname);
        QDomText text=doc.createTextNode(passwd);
        tagname.appendChild(text);
        qDebug()<<Xml.toString()<<endl;
    }
    file.resize(0);
    QTextStream textOutput(&file);
    textOutput<<Xml.toString();
    file.close();
}
