#ifndef PRINTVISITOR_H
#define PRINTVISITOR_H

#include "visitor.h"

class Menu;
class MenuItem;

class PrintVisitor : public Visitor
{
public:
    void visit(Menu *) override;
    void visit(MenuItem *) override;
};

#endif // PRINTVISITOR_H
