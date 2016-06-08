#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "abstractmenuitem.h"

class Menu;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void addMenuItem();
    void selectMenuItem(int index);
    void addNew();
    void open();
    void example();

private:
    void generateMenu();
    void refreshMenu();
    void loadMenu(const QJsonArray &, Menu *);

private:
    Ui::MainWindow *ui;
    Menu *mFairyMe;

};

#endif // MAINWINDOW_H

