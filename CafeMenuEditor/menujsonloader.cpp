#include "menujsonloader.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "menu.h"
#include "menuitem.h"

MenuJsonLoader::MenuJsonLoader(const QString &filePath, QObject *parent) :
    QObject(parent),
    mFilePath(filePath)
{

}

Menu *MenuJsonLoader::load()
{
    Menu *root = nullptr;
    QFile file(mFilePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open file!";
        return root;
    }
    QByteArray data = file.readAll();
    QJsonParseError parseError;
    QJsonDocument doc(QJsonDocument::fromJson(data, &parseError));
    if (parseError.error != QJsonParseError::NoError)
    {
        qDebug() << "Parse error!";
        return root;
    }
    QJsonValue value = doc.object();
    if (value.isObject())
    {
        QJsonObject json = value.toObject();
        root = new Menu(json["title"].toString().toStdString());
        deepLoad(json["children"], root);
    }

    return root;
}

void MenuJsonLoader::deepLoad(const QJsonValue &jsonChildren, Menu *parent)
{
    if (jsonChildren.isArray())
    {
        QJsonArray children = jsonChildren.toArray();
        for (int i = 0; i < children.count(); i++)
        {
            QJsonValue value = children.at(i);
            if (value.isObject())
            {
                QJsonObject child = value.toObject();
                if (child["type"].toString() == "Menu")
                {
                    Menu *menu = new Menu(child["title"].toString().toStdString());
                    parent->addMenuItem(menu);
                    deepLoad(child["children"], menu);
                }
                else
                {
                    MenuItem *item = new MenuItem(
                                    child["title"].toString().toStdString(),
                                    child["price"].toDouble()
                                );
                    parent->addMenuItem(item);
                }
            }
        }
    }
}

