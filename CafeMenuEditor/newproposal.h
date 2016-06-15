#ifndef NEWPROPOSAL_H
#define NEWPROPOSAL_H
#include "menuitem.h"

class newProposal : public MenuItem
{
public:
    newProposal();
private:
    void accept(Visitor &) override;
    void visit();
};

#endif // NEWPROPOSAL_H
