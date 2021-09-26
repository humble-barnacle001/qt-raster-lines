#include "linesmainwidget.h"
#include "ui_linesmainwidget.h"

#include <cmath>

LinesMainWidget::LinesMainWidget(QWidget *parent) : QWidget(parent),
                                                    ui(new Ui::LinesMainWidget), d1(1), d2(1)
{
    ui->setupUi(this);

    // Set defaults
    ui->dda_remarks->hide();
    ui->bresenham_remarks->hide();

    connect(this, &LinesMainWidget::send_data, ui->widget, &DDAWidget::onDataPassed);
    connect(this, &LinesMainWidget::send_data, ui->widget_2, &BresenhamWidget::onDataPassed);

    connect(this, &LinesMainWidget::send_grid_width, ui->widget, &DDAWidget::onGridWidthChanged);
    connect(this, &LinesMainWidget::send_grid_width, ui->widget_2, &BresenhamWidget::onGridWidthChanged);

    connect(this, &LinesMainWidget::reset_shape, ui->widget, &DDAWidget::onResetClicked);
    connect(this, &LinesMainWidget::reset_shape, ui->widget_2, &BresenhamWidget::onResetClicked);

    connect(ui->widget, &DDAWidget::send_time, this, &LinesMainWidget::onTimePassed);
    connect(ui->widget_2, &BresenhamWidget::send_time, this, &LinesMainWidget::onTimePassed);

    connect(ui->widget, &DDAWidget::set_draw_status, this, &LinesMainWidget::setDrawButtonStatus);
    connect(ui->widget_2, &BresenhamWidget::set_draw_status, this, &LinesMainWidget::setDrawButtonStatus);
}

LinesMainWidget::~LinesMainWidget()
{
    delete ui;
}

void LinesMainWidget::on_draw_button_clicked()
{
    emit send_data(ui->x_1->value(), ui->y_1->value(), ui->x_2->value(), ui->y_2->value());
}

void LinesMainWidget::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(351 / 2 / arg1) - 1,
           dim = 2 * arg1 * x - 1;
    ui->widget->setFixedSize(dim, dim);
    ui->widget_2->setFixedSize(dim, dim);
    ui->x_1->setMaximum(x - 1);
    ui->y_1->setMaximum(x - 1);
    ui->x_2->setMaximum(x - 1);
    ui->y_2->setMaximum(x - 1);
    ui->x_1->setMinimum(-x + 1);
    ui->y_1->setMinimum(-x + 1);
    ui->x_2->setMinimum(-x + 1);
    ui->y_2->setMinimum(-x + 1);
    emit send_grid_width(arg1);
    this->on_resetButton_clicked();
}

void LinesMainWidget::on_resetButton_clicked()
{
    ui->x_1->setValue(0);
    ui->y_1->setValue(0);
    ui->x_2->setValue(0);
    ui->y_2->setValue(0);
    ui->dda_remarks->hide();
    ui->bresenham_remarks->hide();
    ui->draw_button->setEnabled(true);
    ui->x_1->setEnabled(true);
    ui->y_1->setEnabled(true);
    ui->x_2->setEnabled(true);
    ui->y_2->setEnabled(true);
    ui->gridWidth->setEnabled(true);
    emit reset_shape();
}

void LinesMainWidget::onTimePassed(QString name, qint64 t)
{
    if (name.compare("widget") == 0)
        ui->dda_remarks->setPlainText(QString::number(t) + "\u03BCs");
    else
        ui->bresenham_remarks->setPlainText(QString::number(t) + "\u03BCs");
}

void LinesMainWidget::setDrawButtonStatus(QString name, bool status)
{
    if (name.compare("widget") == 0)
        d1 = status;
    else
        d2 = status;
    bool res = d1 && d2;
    ui->draw_button->setEnabled(res);
    ui->x_1->setEnabled(res);
    ui->y_1->setEnabled(res);
    ui->x_2->setEnabled(res);
    ui->y_2->setEnabled(res);
    ui->gridWidth->setEnabled(res);
    ui->dda_remarks->setVisible(res);
    ui->bresenham_remarks->setVisible(res);
}
