#include "abstractmenuitem.h"

AbstractMenuItem::AbstractMenuItem(std::string name)
{
    mName = name;
}

AbstractMenuItem::~AbstractMenuItem()
{

}

std::string AbstractMenuItem::name() const
{
    return mName;
}

//std::vector<AbstractMenuItem *> AbstractMenuItem::items() const
//{
//    return mItems;
//}

//void AbstractMenuItem::addMenuItem(AbstractMenuItem *menuItem)
//{
//    mItems.push_back(menuItem);
//}

