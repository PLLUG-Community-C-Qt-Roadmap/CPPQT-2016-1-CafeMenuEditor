#ifndef TEXTEDITPRINTVISITOR_H
#define TEXTEDITPRINTVISITOR_H

#include "visitor.h"

class Menu;
class MenuItem;
class QTextEdit;

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

#endif // TEXTEDITPRINTVISITOR_H
