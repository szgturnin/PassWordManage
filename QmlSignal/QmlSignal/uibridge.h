#ifndef UIBRIDGE_H
#define UIBRIDGE_H
#include<QDebug>
#include <QObject>

class UIBridge : public QObject
{
    Q_OBJECT
public:
    explicit UIBridge(QObject *parent = nullptr);
    Q_INVOKABLE QString getString()const;
    Q_INVOKABLE void revMessageFromQml(QString message);

signals:
    void sendmessagetoShowMessage(QString);

public slots:
};

#endif // UIBRIDGE_H
