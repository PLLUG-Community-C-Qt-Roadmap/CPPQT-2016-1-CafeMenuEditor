#include "menu.h"

#include <iostream>

Menu::Menu(std::string name) :
    AbstractMenuItem(name)
{

}

Menu::~Menu()
{
    std::cout << "Deleted menu: " << name() << std::endl;
    for (AbstractMenuItem *item: items())
    {
        delete item;
    }
}

std::vector<AbstractMenuItem *> Menu::items() const
{
    return mItems;
}

void Menu::addMenuItem(AbstractMenuItem *item)
{
    mItems.push_back(item);
}

void Menu::accept(Visitor &v)
{
    v.visit(this);
}


