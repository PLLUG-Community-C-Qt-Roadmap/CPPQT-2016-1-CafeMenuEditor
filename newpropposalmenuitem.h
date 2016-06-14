#ifndef NEWPROPPOSALMENUITEM_H
#define NEWPROPPOSALMENUITEM_H
#include "menuitem.h"
#include "menuitemeditor.h"

class NewPropposalMenuItem : public MenuItem
{
public:
    NewPropposalMenuItem();
    void accept(Visitor &) override;
    void visit();


};

#endif // NEWPROPPOSALMENUITEM_H
