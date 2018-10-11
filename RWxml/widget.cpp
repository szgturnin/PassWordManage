#include "widget.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vlay=new QVBoxLayout;
    lineAccount = new QLineEdit(NULL);
    linePasswd =new QLineEdit(NULL);
    labelPasswd =new QLabel(QStringLiteral("密码:"));
    labelAccount =new QLabel(QStringLiteral("用户名:"));
    bWrite =new QPushButton(QStringLiteral("写入:"));
    QHBoxLayout *hlay=new QHBoxLayout;
    hlay->addWidget(labelAccount);
    hlay->addWidget(lineAccount);
    QHBoxLayout *hlay1=new QHBoxLayout;
    hlay1->addWidget(labelPasswd);
    hlay1->addWidget(linePasswd);
    vlay->addLayout(hlay,1);
    vlay->addLayout(hlay1,1);
    vlay->addWidget(bWrite);

    passWord =new QLineEdit(NULL);
    username =new QLineEdit(NULL);
    bSarch =new QPushButton(QStringLiteral("查询"));
    labelpassWord =new QLabel(QStringLiteral("密码:"));
    labelusername=new QLabel(QStringLiteral("用户名:"));
    QHBoxLayout *thlay=new QHBoxLayout;
    QHBoxLayout *thlay1=new QHBoxLayout;
    thlay->addWidget(labelpassWord);
    thlay->addWidget(passWord);
    thlay1->addWidget(labelusername);
    thlay1->addWidget(username);
    QVBoxLayout *vlay1=new QVBoxLayout;
    vlay->addLayout(thlay1);
    vlay1->addLayout(thlay);
    vlay->addWidget(bSarch);
    this->setLayout(vlay);
    this->setLayout(vlay1);

    xmlObject=new WRxml;
    connect(bWrite,SIGNAL(clicked()),this,SLOT(WriteXml()));
    connect(bSarch,SIGNAL(clicked()),this,SLOT(SearchXml()));
}

Widget::~Widget()
{

}

void Widget::WriteXml()
{
    //xmlObject->WriteXml(lineAccount->text(),linePasswd->text());
   // xmlObject->WriteXml(lineAccount->text(),linePasswd->text());
   // xmlObject->ChangeXml(lineAccount->text(),linePasswd->text());
    xmlObject->DeleteXml(lineAccount->text(),linePasswd->text());
}

void Widget::SearchXml()
{

}
