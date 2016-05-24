#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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


private:
    void generateMenu();

private:
    Ui::MainWindow *ui;
    Menu *fairyMe;

};

#endif // MAINWINDOW_H

