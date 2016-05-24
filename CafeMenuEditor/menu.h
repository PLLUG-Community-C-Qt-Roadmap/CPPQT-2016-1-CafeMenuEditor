#ifndef MENU_H
#define MENU_H

#include "abstractmenuitem.h"
#include "visitor.h"

class Menu : public AbstractMenuItem
{
public:
    Menu(std::string);
    std::vector<AbstractMenuItem*> items() const;
    void addMenuItem(AbstractMenuItem*);
    void accept(Visitor &) override;

private:
    std::vector<AbstractMenuItem*> mItems;
};

#endif // MENU_H
