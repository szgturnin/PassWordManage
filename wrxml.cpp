﻿#include "wrxml.h"
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QStringList>
#include<QStandardPaths>
WrXml::WrXml(QObject *parent) : QObject(parent)
{
    QString m_standpath=QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    qDebug()<<"m_stabdPath:"<<m_standpath<<endl;
    QFile file(m_standpath+QString("Account.txt"));
    if(file.exists())
    {
        qDebug()<<"file is exist"<<endl;
        qDebug()<<QDir::currentPath()+QString("/Documents/Account.txt")<<endl;
    }
    qDebug()<<"error:"<<file.error()<<"  =   "<<file.errorString()<<endl;
   /* if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        qDebug()<<"open file is failed"<<endl;
        return ;
    }*/
   // QTextStream in(&file);
   // in<<QString("dhjsahdjashd\n")<<QString("467326482\n");//<<是写入的意思咯
    /*if(file.exists())
    {
        qDebug()<<"file is exist"<<endl;
        qDebug()<<QDir::currentPath()+QString("/test.xml")<<endl;

    }
    else
    {
        if(!file.open(QFile::WriteOnly))
        {
            qDebug()<<"open file is failed"<<endl;
            return ;
        }
    }
    QXmlStreamWriter xmlWrite(&file);
    xmlWrite.setAutoFormatting(true);
    xmlWrite.writeStartDocument(QString("1.0"));
    xmlWrite.writeStartElement(QString("test"));
    xmlWrite.writeEndElement();
    xmlWrite.writeEndElement();*/
    file.close();

}

void WrXml::changeXml(QString usernamePasswd)//由于只能传一个参数，所以把密码和账号放到一个参数里面去了
{
    QStringList usernamepasswd=usernamePasswd.split("/");
    QString username=usernamepasswd.at(0);
    QString passwd=usernamepasswd.at(1);
    QFile file(QDir::currentPath()+QString("/Documents/test.xml"));
    qDebug()<<QDir::currentPath()+QString("/Documents/test.xml")<<endl;
    if(!file.open(QFile::ReadOnly|QIODevice::WriteOnly))
    {
        qDebug()<<"open file is fail"<<endl;
        return;
     }
    QDomDocument doc;
    QString errorstr;
    int errorline;
    int errorcolumn;
    if(!doc.setContent(&file,false,&errorstr,&errorline,&errorcolumn))//把FILE文件中的文本读取到doc中
    {
        qDebug() <<"errorStr&&&&："<<errorstr<<"errorLine："<<errorline<<"errorColume："<<errorcolumn;
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

void WrXml::deleteXml(QString username, QString passwd)
{
    QFile file(QDir::currentPath()+QString("/Documents/test.xml"));
    qDebug()<<QDir::currentPath()+QString("/Documents/test.xml")<<endl;
    if(!file.open(QFile::ReadOnly|QIODevice::WriteOnly))
    {
        qDebug()<<"open file is fail"<<endl;
        return;
     }
    QDomDocument doc;
    QString errorstr;
    int errorline;
    int errorcolumn;
    if(!doc.setContent(&file,false,&errorstr,&errorline,&errorcolumn))//把FILE文件中的文本读取到doc中
    {
        qDebug() <<"errorStr&&&&："<<errorstr<<"errorLine："<<errorline<<"errorColume："<<errorcolumn;
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

int WrXml::test()
{
    qDebug()<<"qml test"<<endl;
    return 0;
}

int WrXml::howManyRows()
{
     m_standpath=QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    qDebug()<<"standPath:  "<<m_standpath<<endl;
    QFile file(m_standpath+QString("Account.txt"));
    qDebug()<<m_standpath+QString("Account.txt")<<endl;
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<file.error()<<"  ==  "<<file.errorString()<<endl;
        qDebug()<<"howManyRows Failed"<<endl;
        return -1;
    }
    QTextStream readFile(&file);
    QString line;
    int num=0;
    while (!readFile.atEnd())
    {
        line=readFile.readLine();
        //qDebug()<<"this line:"<<line<<endl;
        num++;
        m_stringVec.push_back(line);

    }
   // qDebug()<<readFile.readAll()<<endl;
    file.close();
    return num;
}

QString WrXml::getStringByNum(int row)
{
    QFile file(m_standpath+QString("Account.txt"));
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"getStringByNum Failed"<<endl;
        return  "errror1";
    }
    QTextStream readFile(&file);
    QString line;
    int num=0;
    while (!readFile.atEnd())
    {
        line=readFile.readLine();
        num++;
        if(num==row)
        {
            return line;
        }
    }
    return "error2";

}

void WrXml::writeAccount(QString accountDetails, QString account, QString passwd)
{
    //m_standpath+QString("/Documents/Account.txt")
    QFile file(m_standpath+QString("Account.txt"));
    qDebug()<<m_standpath+QString("Account.txt")<<endl;
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
    {
        qDebug()<<"writeAccount Failed"<<endl;
        qDebug()<<file.error()<<"  ==  "<<file.errorString()<<endl;

        return  ;
    }
    QTextStream writeFile(&file);
    writeFile<<accountDetails<<"\n"<<account<<"\n"<<passwd<<"\n";
    file.close();
}

void WrXml::createSig()
{
    emit sigCPlus();
}

QString WrXml::readName()
{
    return m_name;
}

void WrXml::setName(QString name)
{
    m_name=name;
    emit nameChanged();
}

void WrXml::slotTest()
{
    qDebug()<<"slot Test";
}
