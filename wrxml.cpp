#include "wrxml.h"
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QStringList>
WrXml::WrXml(QObject *parent) : QObject(parent)
{
    QFile file(QDir::currentPath()+QString("/test.xml"));
    if(file.exists())
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
    xmlWrite.writeEndElement();
    file.close();

}

void WrXml::changeXml(QString usernamePasswd)//由于只能传一个参数，所以把密码和账号放到一个参数里面去了
{
    QStringList usernamepasswd=usernamePasswd.split("/");
    QString username=usernamepasswd.at(0);
    QString passwd=usernamepasswd.at(1);
    QFile file(QDir::currentPath()+QString("/test.xml"));
    qDebug()<<QDir::currentPath()+QString("/test.xml")<<endl;
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
    QFile file(QDir::currentPath()+QString("/test.xml"));
    qDebug()<<QDir::currentPath()+QString("/test.xml")<<endl;
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

    QFile file(QDir::currentPath()+QString("/Account.txt"));
    qDebug()<<QDir::currentPath()+QString("/Account.txt")<<endl;
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"open file filed"<<endl;
        return -1;
    }
    QTextStream readFile(&file);
    QString line;
    int num=0;
    while (readFile.atEnd())
    {
        line=readFile.readLine();
        qDebug()<<"this line:"<<line<<endl;
        num++;
        m_stringVec.push_back(line);

    }
    qDebug()<<readFile.readAll()<<endl;
    return num;
}
