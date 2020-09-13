#include "inifile.h"


IniFile::IniFile(QString filePath, QObject *parent):QObject(parent)
{
    m_settins= new QSettings(filePath,QSettings::IniFormat);
}

void IniFile::write(QString group, QString key, QString value)
{
    m_settins->setValue(group+"/"+key,value);
}

QStringList IniFile::getAllData()
{
    auto keys=m_settins->allKeys();
    QStringList list;
    for (auto i:keys) {
        auto value=m_settins->value(i).toString();
        auto msg=i+"/"+value;
        list.append(msg);
    }
    return list;
}

void IniFile::remove(QString group, QString key)
{
    m_settins->remove(group+"/"+key);
}
