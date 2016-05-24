#include "fillcomboboxvisitor.h"

#include <QString>
#include <QComboBox>
#include <QStringList>
#include <QVariant>

#include "menu.h"
#include "menuitem.h"

FillComboBoxVisitor::FillComboBoxVisitor(QComboBox *comboBox)
    : mComboBox{comboBox}
{

}


void FillComboBoxVisitor::visit(Menu *menu)
{
    QString name = QString::fromStdString(menu->name());
    mComboBox->addItem(name, QVariant::fromValue(static_cast<AbstractMenuItem *>(menu)));

    mParentStack.push(menu);
    for (auto item : menu->items())
    {
        item->accept(*this);
    }
    mParentStack.pop();
}

void FillComboBoxVisitor::visit(MenuItem *item)
{
    QStringList namesList;

    std::stack<AbstractMenuItem *> parentStack{mParentStack};
    while (!parentStack.empty())
    {
        auto item = parentStack.top();
        namesList << QString::fromStdString(item->name());
        parentStack.pop();
    }
    namesList << QString::fromStdString(item->name());

    QString name = namesList.join("::");
    mComboBox->addItem(name, QVariant::fromValue(static_cast<AbstractMenuItem *>(item)));
}
