#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
#include"uibridge.h"
#include"showmessage.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    ShowMessage _showMessage;
    UIBridge _bridge;//绑定步骤1
    QQmlApplicationEngine engine;
    QQmlContext *ctx=engine.rootContext();//绑定步骤2
    ctx->setContextProperty("UiBridge",&_bridge);//绑定步骤3
    QObject::connect(&_bridge,SIGNAL(sendmessagetoShowMessage(QString)),&_showMessage,SLOT(displayMessage(QString)));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
