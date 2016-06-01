#include "menuitem.h"

#include <iostream>

MenuItem::MenuItem(std::string name, double price, std::string ingredients)
    : AbstractMenuItem (name),
      mPrice(price),
      mIngredients(ingredients)
{

}

MenuItem::~MenuItem()
{
    std::cout << "Delete menu item: " << name() << std::endl;
}

double MenuItem::price() const
{
    return mPrice;
}

std::string MenuItem::description() const
{
    return mDescription;
}

std::string MenuItem::ingredients() const
{
    return mIngredients;
}

void MenuItem::accept(Visitor &v)
{
    v.visit(this);
}

