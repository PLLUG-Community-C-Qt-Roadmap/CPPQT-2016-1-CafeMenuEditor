#include "editvisitorwidget.h"
#include "ui_editvisitorwidget.h"

EditVisitorWidget::EditVisitorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditVisitorWidget)
{
    ui->setupUi(this);
}

EditVisitorWidget::~EditVisitorWidget()
{
    delete ui;
}


void EditVisitorWidget::visit(Menu *menu)
{
    Q_UNUSED(menu);
    ui->stackedWidget->setCurrentWidget(ui->menuEditPage);
}

void EditVisitorWidget::visit(MenuItem *item)
{
    Q_UNUSED(item);
    ui->stackedWidget->setCurrentWidget(ui->menuItemEditPage);
}
