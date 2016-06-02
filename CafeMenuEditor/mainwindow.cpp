#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVariant>
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
//     якщо воно чиститься - поточний обраний елемент міняється
//    Від:
//    Alex Chmykhalo
//     ну тобто не стає ніяких елементів
//    Від:
//    Alex Chmykhalo
//     і можливо воно викликає слот з якимось значенням типу 0, чи -1.... ну не важливо.... якщо ми в комбобоксі мали ті всі елементи і до кодного був прикріплений вказівник
//    Від:
//    Alex Chmykhalo
//     і тут ні одного елемента не стало
//    пробуй подебагай, скоріше за все проблема така, як каже Сашко, десь в слоті selectMenuItem стає поганий вказівник на меню або на меню айтему


}




