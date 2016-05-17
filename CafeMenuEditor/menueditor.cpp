#include "menueditor.h"
#include "ui_menueditor.h"

MenuEditor::MenuEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuEditor)
{
    ui->setupUi(this);
}

MenuEditor::~MenuEditor()
{
    delete ui;
}
