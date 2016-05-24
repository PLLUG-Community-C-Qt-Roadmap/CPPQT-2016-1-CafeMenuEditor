#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "menuitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateMenu()
{
    fairyMe = new Menu("CafeFairy");
    MenuItem *menuItem1 = new MenuItem("Water", 10, "water");
    MenuItem *menuItem2 = new MenuItem("juice", 15, "squized fruites");


}

