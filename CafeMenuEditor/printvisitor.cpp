#include "printvisitor.h"

#include <iostream>

#include "menu.h"
#include "menuitem.h"

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

