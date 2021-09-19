#ifndef LINESMAINWIDGET_H
#define LINESMAINWIDGET_H

#include <QWidget>

namespace Ui {
class LinesMainWidget;
}

class LinesMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LinesMainWidget(QWidget *parent = nullptr);
    ~LinesMainWidget();

private slots:
    void on_draw_button_clicked();

    void on_gridWidth_valueChanged(int arg1);

    void on_resetButton_clicked();

signals:
    void send_data(int x1, int y1, int x2, int y2);
    void send_grid_width(int gw);
    void reset_shape();

private:
    Ui::LinesMainWidget *ui;
};

#endif // LINESMAINWIDGET_H
