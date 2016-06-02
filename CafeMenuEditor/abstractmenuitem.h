#ifndef ABSTRACTMENUITEM_H
#define ABSTRACTMENUITEM_H

#include <string>
#include <vector>

#include "visitor.h"

class AbstractMenuItem
{
public:
    AbstractMenuItem(std::string);
    virtual ~AbstractMenuItem();
    std::string name() const;
    virtual void accept(Visitor &v) = 0;

private:
    std::string mName;
};

#endif // ABSTRACTMENUITEM_H
