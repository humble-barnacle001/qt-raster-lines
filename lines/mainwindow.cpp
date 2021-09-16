#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set defaults
    ui->remarks->hide();
    connect(this, &MainWindow::send_data, ui->widget, &DDAWidget::onDataPassed);
    connect(this, &MainWindow::send_data, ui->widget_2, &BresenhamWidget::onDataPassed);

    connect(this, &MainWindow::send_grid_width, ui->widget, &DDAWidget::onGridWidthChanged);
    connect(this, &MainWindow::send_grid_width, ui->widget_2, &BresenhamWidget::onGridWidthChanged);

    connect(this, &MainWindow::reset_shape, ui->widget, &DDAWidget::onResetClicked);
    connect(this, &MainWindow::reset_shape, ui->widget, &BresenhamWidget::onResetClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}

void MainWindow::on_draw_button_clicked()
{
    emit send_data(ui->x_1->value(),ui->y_1->value(),ui->x_2->value(),ui->y_2->value());
//    this->repaint();
}


void MainWindow::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = ceil(341/2/arg1), dim = 2*arg1*(x-1)-1;
    ui->widget->setFixedSize(dim, dim);
    ui->widget_2->setFixedSize(dim, dim);
    emit send_grid_width(arg1);
}


void MainWindow::on_resetButton_clicked()
{
    emit reset_shape();
}

