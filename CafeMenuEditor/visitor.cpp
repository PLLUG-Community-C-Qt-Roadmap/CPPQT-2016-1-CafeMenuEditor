#include "visitor.h"
#include <iostream>
#include <queue>
#include <QString>
#include <QTextEdit>

#include "menu.h"
#include "menuitem.h"

Visitor::Visitor()
{

}

TextEditPrintVisitor::TextEditPrintVisitor(QTextEdit *textedit)
    : mTextEdit(textedit)
    , mLevel{0}
{

}

void PrintVisitor::visit(Menu *menu)
{
    std::cout << menu->name() << std::endl;

    for (auto subItem: menu->items())
    {
        subItem->accept(*this);
    }
}

void PrintVisitor::visit(MenuItem *item)
{
    std::cout << item->name() << std::endl;
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
