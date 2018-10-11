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
class WrXml : public QObject
{
    Q_OBJECT
public:
    explicit WrXml(QObject *parent = nullptr);
    void ChangeXml(QString username,QString passwd);
     void DeleteXml(QString username,QString passwd);
signals:

public slots:
};

#endif // WRXML_H
