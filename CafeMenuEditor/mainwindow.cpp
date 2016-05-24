#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVariant>

#include "menu.h"
#include "menuitem.h"

#include "visitor.h"
#include "fillcomboboxvisitor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<AbstractMenuItem *>("AbstractMenuItem *");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addMenuItem()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(selectMenuItem(int)));

    generateMenu();
    QVariant val = QVariant::fromValue((AbstractMenuItem *)mFairyMe);
    AbstractMenuItem *test = val.value<AbstractMenuItem *>();

    refreshMenu();

    PrintVisitor consolePrintVisitor;
    test->accept(consolePrintVisitor);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addMenuItem()
{
    MenuItem *newItem = new MenuItem("New Item", 100.0);
    mFairyMe->addMenuItem(newItem);

    refreshMenu();
}

#include <QDebug>
void MainWindow::selectMenuItem(int index)
{
    QVariant value = ui->comboBox->itemData(index);
    AbstractMenuItem *item = value.value<AbstractMenuItem *>();
    item->accept(*ui->editVisitorWidget);
}

void MainWindow::generateMenu()
{
    mFairyMe = new Menu("CafeFairy");
    MenuItem *menuItem1 = new MenuItem("Water", 10, "water");
    MenuItem *menuItem2 = new MenuItem("juice", 15, "squized fruites");
    mFairyMe->addMenuItem(menuItem1);
    mFairyMe->addMenuItem(menuItem2);
}

void MainWindow::refreshMenu()
{
    ui->menuTextEdit->clear();
    ui->comboBox->clear();

    TextEditPrintVisitor printVisitor(ui->menuTextEdit);
    mFairyMe->accept(printVisitor);

    FillComboBoxVisitor fillVisitor(ui->comboBox);
    mFairyMe->accept(fillVisitor);
}



