#ifndef MENUITEM_H
#define MENUITEM_H

#include "abstractmenuitem.h"
#include "visitor.h"

class MenuItem : public AbstractMenuItem
{
public:
    MenuItem(std::string name = std::string(), double price = 0.0, std::string ingredients = std::string());

    double price() const;
    std::string description() const;
    std::string ingredients() const;
    void accept(Visitor &) override;

private:
    double mPrice;
    std::string mDescription;
    std::string mIngredients;
};

#endif // MENUITEM_H
