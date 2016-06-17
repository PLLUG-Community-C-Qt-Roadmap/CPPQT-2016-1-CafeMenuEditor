#include "menuitemeditor.h"
#include "ui_menuitemeditor.h"
#include "mainwindow.h"

MenuItemEditor::MenuItemEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuItemEditor)
{
    ui->setupUi(this);
    connect(ui->checkBox,SIGNAL(toggled(bool)),this,SLOT(showN()));
}

MenuItemEditor::~MenuItemEditor()
{
    delete ui;
}

void MenuItemEditor::showN()
{
    MainWindow *mW;
    mW->showMe();
}

