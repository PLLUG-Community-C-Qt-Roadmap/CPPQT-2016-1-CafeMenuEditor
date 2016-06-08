#ifndef MENUJSONLOADER_H
#define MENUJSONLOADER_H

#include <QObject>

class Menu;
class QJsonValue;

class MenuJsonLoader : public QObject
{
    Q_OBJECT
public:
    explicit MenuJsonLoader(const QString &filePath, QObject *parent = 0);

    Menu *load();

signals:

public slots:

private:
    void deepLoad(const QJsonValue &jsonChildren, Menu *parent);

private:
    QString mFilePath;
};

#endif // MENUJSONLOADER_H
