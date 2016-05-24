#ifndef ABSTRACTMENUITEM_H
#define ABSTRACTMENUITEM_H

#include <string>
#include <vector>

#include "visitor.h"

class AbstractMenuItem
{
public:
    AbstractMenuItem(std::string);

    std::string name() const;
    virtual void accept(Visitor &v) = 0;
//    std::vector<AbstractMenuItem*> items() const;
//    void addMenuItem(AbstractMenuItem*);

private:
    std::string mName;
//    std::vector<AbstractMenuItem*> mItems;
};

#endif // ABSTRACTMENUITEM_H
