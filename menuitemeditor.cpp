#include "menuitemeditor.h"
#include "ui_menuitemeditor.h"

MenuItemEditor::MenuItemEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuItemEditor)
{
    ui->setupUi(this);

}

MenuItemEditor::~MenuItemEditor()
{
    delete ui;
}

void MenuItemEditor::newProp()
{
    if(ui->checkBox->isChecked())
    {    }
}
