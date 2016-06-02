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

