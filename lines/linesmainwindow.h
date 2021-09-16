#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LinesMainWindow; }
QT_END_NAMESPACE

class LinesMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    LinesMainWindow(QWidget *parent = nullptr);
    ~LinesMainWindow();

private slots:
    void on_closeButton_clicked();

    void on_draw_button_clicked();

    void on_gridWidth_valueChanged(int arg1);

    void on_resetButton_clicked();

signals:
    void send_data(int x1, int y1, int x2, int y2);
    void send_grid_width(int gw);
    void reset_shape();

private:
    Ui::LinesMainWindow *ui;
};
#endif // MAINWINDOW_H