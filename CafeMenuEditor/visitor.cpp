#include "visitor.h"
#include <iostream>
#include <queue>

#include "menu.h"
#include "menuitem.h"

Visitor::Visitor()
{

}


PrintVisitor::PrintVisitor()
{

}

void PrintVisitor::visit(Menu *menu)
{
    std::queue<AbstractMenuItem*> q;
    q.push(menu);

    while (!q.empty())
    {
        AbstractMenuItem *item = q.front();
        std::cout << item->name() << std::endl;
        q.pop();

//        for (auto *e: item->items())
//        {
//            q.push(e);
//        }
    }
}

void PrintVisitor::visit(MenuItem *item)
{
    std::cout << item->name() << std::endl;
}
