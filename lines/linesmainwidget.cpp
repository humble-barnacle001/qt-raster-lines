#include "linesmainwidget.h"
#include "ui_linesmainwidget.h"

LinesMainWidget::LinesMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LinesMainWidget)
{
    ui->setupUi(this);

    // Set defaults
    ui->remarks->hide();
    connect(this, &LinesMainWidget::send_data, ui->widget, &DDAWidget::onDataPassed);
    connect(this, &LinesMainWidget::send_data, ui->widget_2, &BresenhamWidget::onDataPassed);

    connect(this, &LinesMainWidget::send_grid_width, ui->widget, &DDAWidget::onGridWidthChanged);
    connect(this, &LinesMainWidget::send_grid_width, ui->widget_2, &BresenhamWidget::onGridWidthChanged);

    connect(this, &LinesMainWidget::reset_shape, ui->widget, &DDAWidget::onResetClicked);
    connect(this, &LinesMainWidget::reset_shape, ui->widget, &BresenhamWidget::onResetClicked);

}

LinesMainWidget::~LinesMainWidget()
{
    delete ui;
}

void LinesMainWidget::on_draw_button_clicked()
{
    emit send_data(ui->x_1->value(),ui->y_1->value(),ui->x_2->value(),ui->y_2->value());
//    this->repaint();
}


void LinesMainWidget::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(351/2/arg1), dim = 2*arg1*(x-1)-1;
    ui->widget->setFixedSize(dim, dim);
    ui->widget_2->setFixedSize(dim, dim);
    emit send_grid_width(arg1);
}


void LinesMainWidget::on_resetButton_clicked()
{
    ui->x_1->setValue(0);
    ui->y_1->setValue(0);
    ui->x_2->setValue(0);
    ui->y_2->setValue(0);
    emit reset_shape();
}

