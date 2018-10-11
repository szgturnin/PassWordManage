#ifndef WRXML_H
#define WRXML_H

#include <QObject>
#include<QFile>
#include <QtXml/QDomDocument>
#include<QtXml/QDomProcessingInstruction>
#include<QtXml/QDomElement>
#include<QDir>
#include<QString>
#include<QDebug>
#include<QTextStream>
class WRxml : public QObject
{
    Q_OBJECT
public:
    explicit WRxml(QObject *parent = nullptr);
    void WriteXml(QString username,QString passwd);
    void DeleteXml(QString username,QString passwd);
    void RemoveXml();
    void ChangeXml(QString username,QString passwd);
signals:

public slots:
private:
   QFile *file;
};

#endif // WRXML_H
