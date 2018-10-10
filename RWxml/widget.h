#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QDir>
#include<QPushButton>
#include<QString>
#include"wrxml.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLineEdit *linePasswd;
    QLineEdit *lineAccount;
    QLabel *labelPasswd;
    QLabel *labelAccount;
    QPushButton *bWrite;


    QLineEdit *passWord;
    QLineEdit *username;
    QLabel *labelpassWord;
    QLabel *labelusername;
    QPushButton *bSarch;

    WRxml *xmlObject;
public slots:
    void WriteXml();
    void SearchXml();
};

#endif // WIDGET_H
