#ifndef INIFILE_H
#define INIFILE_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QStringList>
class IniFile : public QObject
{
    Q_OBJECT
public:
    explicit IniFile(QString filePath,QObject *parent = nullptr);

signals:

public slots:
    void write(QString group,QString key,QString value);
    QStringList getAllData();
    void remove(QString group ,QString key);
private:
    QSettings *m_settins;
};

#endif // INIFILE_H
