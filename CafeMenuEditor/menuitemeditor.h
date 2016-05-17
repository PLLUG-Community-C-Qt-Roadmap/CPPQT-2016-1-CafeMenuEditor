#ifndef MENUITEMEDITOR_H
#define MENUITEMEDITOR_H

#include <QWidget>

namespace Ui {
    class MenuItemEditor;
}

class MenuItemEditor : public QWidget
{
    Q_OBJECT

public:
    explicit MenuItemEditor(QWidget *parent = 0);
    ~MenuItemEditor();

private:
    Ui::MenuItemEditor *ui;
};

#endif // MENUITEMEDITOR_H
