#ifndef VISITOR_H
#define VISITOR_H

//#include "menu.h"

class QTextEdit;
class Menu;
class MenuItem;

class Visitor
{
public:
    Visitor();
    virtual void visit(Menu *) = 0;
    virtual void visit(MenuItem *) = 0;
};

#endif // VISITOR_H
