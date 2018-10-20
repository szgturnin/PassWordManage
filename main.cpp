#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"wrxml.h"
#include<QtQml>
#include<QtQuick/QQuickView>
/*另外一种的注册C++到qml中的方法没有使用，是因为那种方法目前据我所知只能注册1种一下的方法，而我读写xml的方法事先先写好了，有2个参数，所以就
换种注册qml的方法好了*/
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    /*------------------把C++类的对象导入到qml中使用--------------*/
    //QQuickView viewer;
    //viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    //viewer.rootContext()->setContextProperty("xml",new WrXml);//这个"xml"就代表了  WrXml这个new出来的对象。可以在qml中被使用
    //viewer.setSource(QUrl("qrc://main.qml"));
   // viewer.show();
    /*------------------把C++类的对象导入到qml中使用--------------*/
    //QQmlApplicationEngine +window的程序结构
   // QQmlApplicationEngine engine;
   // engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
   // if (engine.rootObjects().isEmpty())
     //   return -1;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("xml",new WrXml);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
