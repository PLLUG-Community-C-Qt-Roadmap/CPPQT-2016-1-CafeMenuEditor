#ifndef MENUEDITOR_H
#define MENUEDITOR_H

#include <QWidget>

namespace Ui {
    class MenuEditor;
}

class MenuEditor : public QWidget
{
    Q_OBJECT

public:
    explicit MenuEditor(QWidget *parent = 0);
    ~MenuEditor();

private:
    Ui::MenuEditor *ui;
};

#endif // MENUEDITOR_H
