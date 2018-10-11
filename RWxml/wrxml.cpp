#include "wrxml.h"
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
WRxml::WRxml(QObject *parent) : QObject(parent)
{
    //打开或创建文件
     QFile file(QDir::currentPath()+QString("/test.xml"));
    if(file.exists())
    {
        qDebug()<<"file is exist"<<endl;
        qDebug()<<QDir::currentPath()+QString("//test")<<endl;
    }
    else
    {
        if(!file.open(QFile::WriteOnly)) //可以用QIODevice，Truncate表示清空原来的内容
        {
            qDebug()<<"open file is fail"<<endl;
            return;
        }
    }
   /* QDomDocument doc;
    //写入xml头部
    QDomProcessingInstruction instruction; //添加处理命令
    instruction=doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QTextStream out_stream(&file);
    doc.save(out_stream,0);
    file.close();*/
    QXmlStreamWriter xmlwriter(&file);
    xmlwriter.setAutoFormatting(true);
    xmlwriter.writeStartDocument();
    xmlwriter.writeEndElement();
    file.close();
}

void WRxml::WriteXml(QString username,QString passwd)//能增加的话最好，不能的话应该先读，并保存，然后再append,然后再写入
{
    QFile file(QDir::currentPath()+QString("/test.xml"));
    /*if(!file.open(QFile::WriteOnly|QFile::Truncate))
    {
        qDebug()<<"open file is fail"<<endl;
        return;
     }*/
    if(!file.open(QFile::Text|QFile::ReadOnly|QIODevice::WriteOnly))
    {
        qDebug()<<"open file is fail"<<endl;
        return;
     }
    /*-----------------先全部读进来--------------------*/
    QDomDocument doc;
    if(!doc.setContent(&file))//把FILE文件中的文本读取到doc中
    {
        file.close();
        return ;
    }
   // qDebug()<<doc.toString()<<endl;
    QDomDocument Xml;
    QDomElement rootElem=doc.documentElement();

    //qDebug()<<rootElem.tagName()<<endl;

    QDomElement main=  Xml.createElement(rootElem.tagName());
    Xml.appendChild(main);

    //qDebug()<<Xml.toString()<<endl;
    QDomNode rootNode=rootElem.firstChild();
    while (!rootNode.isNull())
    {
        QDomElement fileElem=rootNode.toElement();
        if(!fileElem.isNull())
        {
            QDomElement tagname=doc.createElement(fileElem.tagName());
            main.appendChild(tagname);
            //Xml.appendChild(tagname);
           // qDebug()<<fileElem.tagName()<<endl;

            QDomText text=doc.createTextNode(fileElem.text());

            tagname.appendChild(text);

           // qDebug()<<fileElem.text()<<endl;
        }
        rootNode=rootNode.nextSibling();
    }
    QDomElement tagname=doc.createElement(username);
    main.appendChild(tagname);
    QDomText text=doc.createTextNode(passwd);
    tagname.appendChild(text);
    qDebug()<<Xml.toString()<<endl;//上面这个while循环中已经在doc中把所有的节点信息读取进去了


    /*-----------每次都清空，重写过------------------*/
   /* QXmlStreamWriter xmlwriter(&file);
    xmlwriter.setAutoFormatting(true);
    xmlwriter.writeStartDocument();
    xmlwriter.writeStartElement("test");

    xmlwriter.writeTextElement(username,passwd);



    xmlwriter.writeEndElement();
    xmlwriter.writeEndDocument();*/
    file.resize(0);//清空file中管理的文本
    QTextStream textOutput(&file);
    textOutput<<Xml.toString();
    //这段代码是直接在xml文本上添加xml.tostring()的内容

    file.close();
}

void WRxml::DeleteXml(QString username,QString passwd)//如果找到了就删除，没有找到就添加
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




void WRxml::RemoveXml()
{

}

void WRxml::ChangeXml(QString username,QString passwd)//如果相等就修改，如果不存在就添加
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
    /*//打开文件
        QFile file("test.xml"); //相对路径、绝对路径、资源路径都可以
        if(!file.open(QFile::ReadOnly))
            return;

        //更新一个标签项,如果知道xml的结构，直接定位到那个标签上定点更新
        //或者用遍历的方法去匹配tagname或者attribut，value来更新
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();

        QDomElement root=doc.documentElement();
        QDomNodeList list=root.elementsByTagName("book");
        QDomNode node=list.at(list.size()-1).firstChild(); //定位到第三个一级子节点的子元素
        QDomNode oldnode=node.firstChild(); //标签之间的内容作为节点的子节点出现,当前是Pride and Projudice
        node.firstChild().setNodeValue("Emma");
        QDomNode newnode=node.firstChild();
        node.replaceChild(newnode,oldnode);

        if(!file.open(QFile::WriteOnly|QFile::Truncate))
            return;
        //输出到文件
        QTextStream out_stream(&file);
        doc.save(out_stream,4); //缩进4格
        file.close();*/
}

