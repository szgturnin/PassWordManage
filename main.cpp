#include <QApplication>
#include <QQmlApplicationEngine>
#include "wrxml.h"
#include <QtQml>
#include <QQuickItem>
#include <QtQuick/QQuickView>
#include <QObject>
#include <QList>

#include <QQuickWidget>
/*另外一种的注册C++到qml中的方法没有使用，是因为那种方法目前据我所知只能注册1种一下的方法，而我读写xml的方法事先先写好了，有2个参数，所以就
换种注册qml的方法好了*/
int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    /*------------------把C++类的对象导入到qml中使用--------------*/
    qmlRegisterType<WrXml>("szg.test.customClassToQml", 1, 0, "WrXml");

    //    QQuickView viewer;
    //    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    //    viewer.rootContext()->setContextProperty("xml",new WrXml);//这个"xml"就代表了  WrXml这个new出来的对象。可以在qml中被使用
    //    viewer.setSource(QUrl("qrc:/main.qml"));

    /*------------------把C++类的对象导入到qml中使用--------------*/
    //QQmlApplicationEngine +window的程序结构
    // QQmlApplicationEngine engine;
    // engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    // if (engine.rootObjects().isEmpty())
    //   return -1;


    //方法1
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("xml",new WrXml);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    QObject *root = NULL;
    QList<QObject*> rootObjects=engine.rootObjects();
    int count=rootObjects.size();
    qDebug()<<count;
    for(int i=0;i<count;i++)
    {
        qDebug()<<rootObjects.at(i)->objectName();
    }
    root=rootObjects.at(0);
    QObject *quitButton=root->findChild<QObject*>("windowName");
    //QObject::connect(quitButton,SIGNAL(clicked()),);
    bool ret=QMetaObject::invokeMethod(quitButton,"onClicked");
    qDebug()<<"clicked:"<<ret;



    //获取qml中的对象
    //    QQuickView Qmlviewer;
    //    Qmlviewer.setSource(QUrl("qrc:/StyleButton.qml"));
    //    auto styBtnObject=Qmlviewer.rootObject();
    //    qDebug()<<"rootObject name:"<<styBtnObject->objectName();
    //    QObject *btnObj=styBtnObject->findChild<QObject*>("buttonObj");
    //    if(btnObj){
    //        qDebug()<<"finchild success";
    //        bool ret=QMetaObject::invokeMethod(btnObj,"onClicked");
    //        qDebug()<<"clicked:"<<ret;
    //    }



    return app.exec();
}
