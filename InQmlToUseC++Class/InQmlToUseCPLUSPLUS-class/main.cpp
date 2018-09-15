#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"colormaker.h"
#include<QtQml>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qmlRegisterType<ColorMaker>("QmlAndCplusClass",1,0,"ColorMaker");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
