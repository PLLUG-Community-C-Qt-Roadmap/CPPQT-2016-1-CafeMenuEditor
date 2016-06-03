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
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(addNew()));

    connect(ui->action_Open, SIGNAL(triggered(bool)), this, SLOT(open()));

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

void MainWindow::loadMenu(const QJsonArray &jsonChildren, Menu *parent)
{
    for (int index = 0; index < jsonChildren.size(); index++)
    {
        QJsonObject child(jsonChildren[index].toObject());
        if (child["type"].toString() == "Menu")
        {
            Menu *menu = new Menu(child["title"].toString().toStdString());
            parent->addMenuItem(menu);
            loadMenu(child["children"].toArray(), menu);
        }
        else
        {
            MenuItem *item = new MenuItem(
                    child["title"].toString().toStdString(),
                    child["price"].toDouble()
                );
            parent->addMenuItem(item);
        }
    }
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "JSON files (*.json);;All files (*.*)");
    if (fileName.isEmpty())
    {
        return;
    }
    QFile menuFile(fileName);
    if (!menuFile.open(QIODevice::ReadOnly))
    {
        return;
    }
    QByteArray data = menuFile.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    QJsonObject json(doc.object());
    delete mFairyMe;
    mFairyMe = new Menu(json["title"].toString().toStdString());
    loadMenu(json["children"].toArray(), mFairyMe);
    refreshMenu();
}




