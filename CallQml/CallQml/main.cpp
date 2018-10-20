#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QMetaObject>
#include<QDebug>
#include<QColor>
#include<QVariant>
#include<QString>
#include"changeqmlcolor.h"
/*1.如果使用QQuickView +Item 的程序结构方式，通过QQuickView 的rootObject()直接可以得到QML文档的根Item对象。而callQml采用QQMLApplication
+Window的程序结构方式，Qml文档根对象的获取就麻烦些。
2.quitButton按钮，把他的clicked（）信号连接到QGuiApplication 的quit()槽上
然而  通过"textLabel "找到的textLabel对象。首先我企图使用invokeMe()调用setText()方法来改变textLabel的文本，但是却失败了
是因为QML中的Text对象对应着C++中的QQuickText类，而QQuickText没有"setText"的槽或者是可以调用的方法。
后来调用存在的doLayout()，这次才成功了。
*/
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    /*-----------------------------Do it-----------------------*/
    QObject *root = NULL;
    QList<QObject*> rootObjects=engine.rootObjects();
    int count=rootObjects.size();
    for(int i=0;i<count;i++)
    {
        if(rootObjects.at(i)->objectName()=="rootObject")
        {
            root = rootObjects.at(i);
            break;
        }
    }
    new ChangeQmlColor(root);
    QObject *quitButton=root->findChild<QObject*>("quitButton");
    if(quitButton)
    {
        QObject::connect(quitButton,SIGNAL(clicked()),&app,SLOT(quit()));// 对应的qml在C++里面是QObject的对象

    }
    QObject *textLabel=root->findChild<QObject*>("textLable");
    if(textLabel)
    {
        bool bRet=QMetaObject::invokeMethod(textLabel,"setText",Q_ARG(QString,"world Hello"));
        qDebug()<<"call setText return :"<<bRet<<endl;
        textLabel->setProperty("color",QColor::fromRgb(255,0,0));
        bRet=QMetaObject::invokeMethod(textLabel,"doLayout");//调用对应的方法要看C++类里面是否存在，方法名字的字符串要正确才行
        qDebug()<<"call dolayout return :"<<bRet<<endl;

    }
    /*-----------------------------Do it-----------------------*/
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
