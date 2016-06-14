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
    mParents.append(name);
    mComboBox->addItem(mParents.join("::"), QVariant::fromValue(static_cast<AbstractMenuItem *>(menu)));

    for (auto item : menu->items())
    {
        item->accept(*this);
    }

    mParents.removeLast();
}

void FillComboBoxVisitor::visit(MenuItem *item)
{
    mParents << QString::fromStdString(item->name());
    mComboBox->addItem(mParents.join("::"), QVariant::fromValue(static_cast<AbstractMenuItem *>(item)));
    mParents.removeLast();
}
