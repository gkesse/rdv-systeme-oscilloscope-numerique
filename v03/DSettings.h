#pragma once

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QSettings>

class DSettings : public QObject
{
    Q_OBJECT

public:
    explicit DSettings(const QString &fileName, QObject *parent = nullptr);
    ~DSettings();
    QSettings::Status status() const;
    QString escape(const QString &str);
    void setValue(const QString &key, const QString &value);
    void setValue(const QString &key, int value);

private:
    QFile file;
    QTextStream outstream;
};
