#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void polygon_change_widget(int index);

private slots:
    void on_closeButton_clicked();
    void menu_item_clicked(QAction *action);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
