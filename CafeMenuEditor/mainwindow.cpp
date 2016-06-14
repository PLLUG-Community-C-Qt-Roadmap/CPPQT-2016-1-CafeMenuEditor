#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVariant>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

#include "menu.h"
#include "menuitem.h"
#include "menujsonloader.h"

#include "visitor.h"
#include "texteditprintvisitor.h"
#include "fillcomboboxvisitor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<AbstractMenuItem *>("AbstractMenuItem *");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addMenuItem()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectMenuItem(int)));
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(addNew()));
    connect(ui->action_Open, SIGNAL(triggered(bool)), this, SLOT(open()));
    connect(ui->actionView_Example_Menu, SIGNAL(triggered()), this, SLOT(example()));
    connect(ui->action_About_Menu_Editor,SIGNAL(triggered()), this,SLOT(aboutMenu()));
    connect(ui->actionAbout_Qt, SIGNAL(triggered()),this,SLOT(aboutQt()));
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

void MainWindow::selectMenuItem(int index)
{
    if (index < 0)
        return;
    QVariant value = ui->comboBox->itemData(index);
    AbstractMenuItem *item = value.value<AbstractMenuItem *>();
    item->accept(*ui->editVisitorWidget);
}

void MainWindow::generateMenu()
{
    mFairyMe = new Menu("CafeFairy");

    Menu *drinks = new Menu("Drinks");
    MenuItem *water = new MenuItem("Water", 10, "water");
    MenuItem *juice = new MenuItem("Juice", 15, "squized fruites");
    drinks->addMenuItem(water);
    drinks->addMenuItem(juice);

    Menu *deserts = new Menu("Deserts");
    MenuItem *iceCream = new MenuItem("Ice Cream", 10, "Chemical ingredients");
    MenuItem *cake = new MenuItem("Cake", 20, "Chemical ingredients");
    deserts->addMenuItem(iceCream);
    deserts->addMenuItem(cake);

    mFairyMe->addMenuItem(drinks);
    mFairyMe->addMenuItem(deserts);
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

void MainWindow::addNew()
{
    delete mFairyMe;
    mFairyMe = new Menu("New Cafe Menu");
    refreshMenu();
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "JSON files (*.json);;All files (*.*)");
    if (fileName.isEmpty())
    {
        return;
    }
    delete mFairyMe;
    MenuJsonLoader jsonLoader(fileName, this);
    mFairyMe = jsonLoader.load();
    refreshMenu();
}

void MainWindow::example()
{
    delete mFairyMe;
    generateMenu();
    refreshMenu();
}

void MainWindow::aboutMenu()
{
    QMessageBox msg;
    msg.information(this, "Menu Editor", "v.1.0", QMessageBox::Ok);
}

void MainWindow::aboutQt()
{
    QMessageBox msg;
    msg.aboutQt(this, "about Qt");
}




