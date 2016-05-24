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

class PrintVisitor : public Visitor
{
public:
    void visit(Menu *) override;
    void visit(MenuItem *) override;
};

class TextEditPrintVisitor : public Visitor
{
public:
    TextEditPrintVisitor(QTextEdit *textedit);

    void visit(Menu *) override;
    void visit(MenuItem *) override;

private:
    QTextEdit *mTextEdit;
    int mLevel;
};

#endif // VISITOR_H
