#ifndef FILLCOMBOBOXVISITOR_H
#define FILLCOMBOBOXVISITOR_H

#include "visitor.h"

#include <QMetaType>
#include <QStringList>

class QComboBox;
class AbstractMenuItem;

class FillComboBoxVisitor : public Visitor
{
public:
    FillComboBoxVisitor(QComboBox *comboBox);

    // Visitor interface
public:
    virtual void visit(Menu *) override;
    virtual void visit(MenuItem *) override;

private:
    QComboBox *mComboBox;
    QStringList mParents;
};

Q_DECLARE_METATYPE(AbstractMenuItem *)

#endif // FILLCOMBOBOXVISITOR_H
