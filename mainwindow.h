#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_closeButton_clicked();
    void menu_item_clicked(QAction *);
//    void menu_hover();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
