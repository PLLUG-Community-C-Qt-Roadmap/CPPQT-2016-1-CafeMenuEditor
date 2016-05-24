#ifndef EDITVISITORWIDGET_H
#define EDITVISITORWIDGET_H

#include <QWidget>
#include "visitor.h"

namespace Ui {
    class EditVisitorWidget;
}

class EditVisitorWidget
        : public QWidget
        , public Visitor
{
    Q_OBJECT

public:
    explicit EditVisitorWidget(QWidget *parent = 0);
    ~EditVisitorWidget();

private:
    Ui::EditVisitorWidget *ui;

    // Visitor interface
public:
    virtual void visit(Menu *) override;
    virtual void visit(MenuItem *) override;
};

#endif // EDITVISITORWIDGET_H
