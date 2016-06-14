#include "texteditprintvisitor.h"

#include <QString>
#include <QTextEdit>

#include "menu.h"
#include "menuitem.h"

TextEditPrintVisitor::TextEditPrintVisitor(QTextEdit *textedit)
    : mTextEdit(textedit)
    , mLevel{0}
{

}

void TextEditPrintVisitor::visit(Menu *menu)
{
    QString indent;
    for (int level = 0; level < mLevel; ++level)
    {
        indent += "    ";
    }

    QString text = indent + QString::fromStdString(menu->name());
    mTextEdit->append(text);

    mLevel ++;
    for (auto subItem: menu->items())
    {
        subItem->accept(*this);
    }
    mLevel --;
}

void TextEditPrintVisitor::visit(MenuItem *item)
{
    QString indent;
    for (int level = 0; level < mLevel; ++level)
    {
        indent += "    ";
    }

    QString text = indent + QString::fromStdString(item->name());
    mTextEdit->append(text);
}
