#include "menu.h"

Menu::Menu(std::string name) :
    AbstractMenuItem(name)
{

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


