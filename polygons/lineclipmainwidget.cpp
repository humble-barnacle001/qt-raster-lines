#include "lineclipmainwidget.h"
#include "ui_lineclipmainwidget.h"

LineClipMainWidget::LineClipMainWidget(QWidget *parent) : QWidget(parent),
                                                          ui(new Ui::LineClipMainWidget)
{
    ui->setupUi(this);

    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->drawButton->setEnabled(false);

    connect(this, &LineClipMainWidget::send_grid_width, ui->widget, &PolygonGraphWidget::onGridWidthChanged);

    connect(this, &LineClipMainWidget::reset_shape, ui->widget, &PolygonGraphWidget::onResetClicked);

    connect(ui->widget, &PolygonGraphWidget::send_time, this, &LineClipMainWidget::onTimePassed);

    connect(ui->widget, &PolygonGraphWidget::set_draw_status, this, &LineClipMainWidget::setDrawButtonStatus);

    connect(ui->widget, &PolygonGraphWidget::update_progress, this, &LineClipMainWidget::setProgressUpdate);

    connect(ui->drawPolygonButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::drawPolygon);

    connect(ui->drawButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::polygonOperation);

    connect(this, &LineClipMainWidget::send_XY, ui->widget, &LineClipGraphWidget::translateXYChanged);

    on_gridWidth_valueChanged(5);
}

LineClipMainWidget::~LineClipMainWidget()
{
    delete ui;
}

void LineClipMainWidget::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(480 / 2 / arg1) - 1,
           dim = 2 * arg1 * x - 1;
    ui->widget->setFixedSize(dim, dim);
    emit send_grid_width(arg1);
    this->on_resetButton_clicked();
}

void LineClipMainWidget::on_resetButton_clicked()
{
    ui->drawButton->setEnabled(false);
    ui->drawPolygonButton->setEnabled(true);
    ui->gridWidth->setEnabled(true);
    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    emit reset_shape();
}

void LineClipMainWidget::setDrawButtonStatus(QString, bool status, bool showTime)
{
    ui->drawButton->setEnabled(status);
    ui->drawPolygonButton->setEnabled(status);
    ui->gridWidth->setEnabled(status);
    ui->resetButton->setEnabled(status);
    ui->spinBox->setEnabled(status);
    ui->spinBox_2->setEnabled(status);
    if (showTime)
    {
        ui->timeDisplay->setVisible(status);
        ui->progressBar->setVisible(status);
    }
}

void LineClipMainWidget::onTimePassed(QString, qint64 t)
{
    ui->timeDisplay->setPlainText(QString::number(t) + "\u03BCs");
}

void LineClipMainWidget::setProgressUpdate(QString, int value)
{
    if (!ui->progressBar->isVisible())
        ui->progressBar->setVisible(true);
    ui->progressBar->setValue(value);
}

void LineClipMainWidget::on_spinBox_valueChanged(int)
{
    emit send_XY(QPoint(ui->spinBox->value(), ui->spinBox_2->value()));
}

void LineClipMainWidget::on_spinBox_2_valueChanged(int)
{
    emit send_XY(QPoint(ui->spinBox->value(), ui->spinBox_2->value()));
}
