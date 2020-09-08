#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/test.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QList<QObject*> rootObjects=engine.rootObjects();
    int count=rootObjects.size();
    qDebug()<<count;
    for(int i=0;i<count;i++)
    {
        qDebug()<<rootObjects.at(i)->objectName();
        if("windowObj"==rootObjects.at(i)->objectName()){
            auto root=rootObjects.at(0);
            auto btn=root->findChild<QObject*>("btn");
            qDebug()<<btn->objectName();
            QMetaObject::invokeMethod(btn,"testSig");
        }
    }

    return app.exec();
}
