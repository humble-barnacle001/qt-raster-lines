#include "linesmainwindow.h"
#include "ui_linesmainwindow.h"

#include <iostream>
#include <QDate>
#include <cmath>

LinesMainWindow::LinesMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LinesMainWindow)
{
    ui->setupUi(this);

    // Set defaults
    ui->remarks->hide();
    connect(this, &LinesMainWindow::send_data, ui->widget, &DDAWidget::onDataPassed);
    connect(this, &LinesMainWindow::send_data, ui->widget_2, &BresenhamWidget::onDataPassed);

    connect(this, &LinesMainWindow::send_grid_width, ui->widget, &DDAWidget::onGridWidthChanged);
    connect(this, &LinesMainWindow::send_grid_width, ui->widget_2, &BresenhamWidget::onGridWidthChanged);

    connect(this, &LinesMainWindow::reset_shape, ui->widget, &DDAWidget::onResetClicked);
    connect(this, &LinesMainWindow::reset_shape, ui->widget, &BresenhamWidget::onResetClicked);

}

LinesMainWindow::~LinesMainWindow()
{
    delete ui;
}

void LinesMainWindow::on_closeButton_clicked()
{
    this->close();
}

void LinesMainWindow::on_draw_button_clicked()
{
    emit send_data(ui->x_1->value(),ui->y_1->value(),ui->x_2->value(),ui->y_2->value());
//    this->repaint();
}


void LinesMainWindow::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(341/2/arg1), dim = 2*arg1*(x-1)-1;
    ui->widget->setFixedSize(dim, dim);
    ui->widget_2->setFixedSize(dim, dim);
    emit send_grid_width(arg1);
}


void LinesMainWindow::on_resetButton_clicked()
{
    emit reset_shape();
}

