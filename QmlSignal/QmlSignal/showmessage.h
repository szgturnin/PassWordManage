#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include <QObject>

class ShowMessage : public QObject
{
    Q_OBJECT
public:
    explicit ShowMessage(QObject *parent = nullptr);

signals:

public slots:
    void displayMessage(QString message);
};

#endif // SHOWMESSAGE_H
