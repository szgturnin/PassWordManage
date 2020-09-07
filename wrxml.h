#ifndef WRXML_H
#define WRXML_H

#include<QObject>
#include<QFile>
#include<QtXml/QDomDocument>
#include<QtXml/QDomProcessingInstruction>
#include<QtXml/QDomElement>
#include<QDir>
#include<QString>
#include<QDebug>
#include<QTextStream>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QTextStream>
#include<QVector>
class WrXml : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(int test1 READ test WRITE ChangeXml)//读属性，不能带参数，否则会报错
    Q_PROPERTY(QString name READ readName WRITE setName NOTIFY nameChanged)
    Q_ENUMS(TESTENUM)
public:
    enum TESTENUM{
        ZERO,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE
    };
    explicit WrXml(QObject *parent = nullptr);
    /*从下面3个函数测试来看，基本调用下面这些宏，也不需要上面Q_PROPERTY这个宏其实就可以实现qml调用C++的代码，并且参数不受限制
但是函数名的首写字母最好不要大写，因为他会要求什么new的问题*/
   Q_INVOKABLE void changeXml(QString usernamePasswd);
     Q_INVOKABLE void deleteXml(QString username,QString passwd);
     Q_INVOKABLE int test();
   // Q_INVOKABLE QString readText();
    Q_INVOKABLE int howManyRows();//在mac中是这样的，如果你声明了这个函数为qml可以调用的，
    //那么你就一定要有函数的实现。否则就会报错:-1: error: symbol(s) not found for architecture x86_64
    Q_INVOKABLE QString getStringByNum(int row);
    Q_INVOKABLE void writeAccount(QString accountDetails,QString account,QString passwd);

    Q_INVOKABLE void createSig();

    QString readName();
    void setName(QString name);
signals:
    void sigCPlus();//c++发出的信号
    void nameChanged();
public slots:
    void slotTest();
private:
     QString m_standpath;
     int test11;
     QVector<QString> m_stringVec;
     QString m_name;
};

#endif // WRXML_H
