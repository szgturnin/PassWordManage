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
    if(!file.open(QFile::Text|QFile::ReadOnly))
    {
        qDebug()<<"open file is fail"<<endl;
        return;
     }
    /*-----------------先全部读进来--------------------*/
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return ;
    }
   // qDebug()<<doc.toString()<<endl;
    QDomDocument Xml;
    QString name;
    QDomElement rootElem=doc.documentElement();

    qDebug()<<rootElem.tagName()<<endl;

    QDomElement main=  Xml.createElement(rootElem.tagName());
    Xml.appendChild(main);

    qDebug()<<Xml.toString()<<endl;
    QDomNode rootNode=rootElem.firstChild();
    while (!rootNode.isNull())
    {
        QDomElement fileElem=rootNode.toElement();
        if(!fileElem.isNull())
        {
            QDomElement tagname=doc.createElement(fileElem.tagName());

            //Xml.appendChild(tagname);
            qDebug()<<fileElem.tagName()<<endl;

            QDomText text=doc.createTextNode(fileElem.text());

           // tagname.appendChild(text);

            qDebug()<<fileElem.text()<<endl;
        }
        rootNode=rootNode.nextSibling();
    }
    qDebug()<<Xml.toString()<<endl;//上面这个while循环中已经在doc中把所有的节点信息读取进去了


    /*-----------每次都清空，重写过------------------*/
   /* QXmlStreamWriter xmlwriter(&file);
    xmlwriter.setAutoFormatting(true);
    xmlwriter.writeStartDocument();
    xmlwriter.writeStartElement("test");

    xmlwriter.writeTextElement(username,passwd);



    xmlwriter.writeEndElement();
    xmlwriter.writeEndDocument();*/
    file.close();
}

void WRxml::ReadXml()
{
    QFile file(QDir::currentPath()+QString("/test.xml"));
    if(!file.open(QFile::Text|QFile::ReadOnly))
    {
        qDebug()<<"open file is fail"<<endl;
        return;
     }
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return ;
    }
    QString name;
    QDomElement rootElem=doc.documentElement();
    QDomNode rootNode=rootElem.firstChild();
    while (!rootNode.isNull())
    {
        QDomElement fileElem=rootNode.toElement();
        if(!fileElem.isNull())
        {
            name=fileElem.tagName();
            qDebug()<<name<<"   "<<fileElem.text()<<endl;
        }
        rootNode=rootNode.nextSibling();
    }
}

void WRxml::AddXml()
{
    //打开文件
        QFile file("test.xml"); //相对路径、绝对路径、资源路径都可以
        if(!file.open(QFile::ReadOnly))
            return;

        //增加一个一级子节点以及元素
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();

        QDomElement root=doc.documentElement();
        QDomElement book=doc.createElement("book");
        book.setAttribute("id",3);
        book.setAttribute("time","1813/1/27");
        QDomElement title=doc.createElement("title");
        QDomText text;
        text=doc.createTextNode("Pride and Prejudice");
        title.appendChild(text);
        book.appendChild(title);
        QDomElement author=doc.createElement("author");
        text=doc.createTextNode("Jane Austen");
        author.appendChild(text);
        book.appendChild(author);
        root.appendChild(book);

        if(!file.open(QFile::WriteOnly|QFile::Truncate)) //先读进来，再重写，如果不用truncate就是在后面追加内容，就无效了
            return;
        //输出到文件
        QTextStream out_stream(&file);
        doc.save(out_stream,4); //缩进4格
        file.close();
}

void WRxml::RemoveXml()
{
    //打开文件
        QFile file("test.xml"); //相对路径、绝对路径、资源路径都可以
        if(!file.open(QFile::ReadOnly))
            return;

        //删除一个一级子节点及其元素，外层节点删除内层节点于此相同
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();  //一定要记得关掉啊，不然无法完成操作

        QDomElement root=doc.documentElement();
        QDomNodeList list=doc.elementsByTagName("book"); //由标签名定位
        for(int i=0;i<list.count();i++)
        {
            QDomElement e=list.at(i).toElement();
            if(e.attribute("time")=="2007/5/25")  //以属性名定位，类似于hash的方式，warning：这里仅仅删除一个节点，其实可以加个break
                root.removeChild(list.at(i));
        }

        if(!file.open(QFile::WriteOnly|QFile::Truncate))
            return;
        //输出到文件
        QTextStream out_stream(&file);
        doc.save(out_stream,4); //缩进4格
        file.close();
}

void WRxml::UpdateXml()
{
    //打开文件
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
        file.close();
}

