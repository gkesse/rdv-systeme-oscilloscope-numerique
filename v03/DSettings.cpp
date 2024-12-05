#include "DSettings.h"

#include <QSettings>

DSettings::DSettings(const QString &fileName, QObject *parent)
    : QObject(parent)
{
    if (fileName.isNull())
        return;

    file.setFileName(fileName);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        outstream.setDevice(&file);
        outstream << "[General]" << Qt::endl;
    }
}

DSettings::~DSettings()
{
    if (file.isOpen())
    {
        file.close();
    }
}

QSettings::Status DSettings::status() const
{
    if (file.isOpen())
        return QSettings::NoError;
    else
        return QSettings::AccessError;
}

QString DSettings::escape(const QString &str)
{
    if (str.indexOf("\n") == -1 && str.indexOf("\a") == -1 && str.indexOf(";") == -1)
        return str;

    QString escaped(str);
    escaped = escaped.replace("\n", "\\n");
    escaped = escaped.replace("\a", "\\a");
    return "\"" + escaped + "\"";
}

void DSettings::setValue(const QString &key, const QString &value)
{
    outstream << key << "=" << escape(value) << Qt::endl;
}

void DSettings::setValue(const QString &key, int value)
{
    setValue(key, QString("%1").arg(value));
}
