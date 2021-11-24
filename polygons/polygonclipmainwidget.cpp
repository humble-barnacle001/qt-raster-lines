#include "polygonclipmainwidget.h"
#include "ui_polygonclipmainwidget.h"

PolygonClipMainWidget::PolygonClipMainWidget(QWidget *parent) : QWidget(parent),
                                                                ui(new Ui::PolygonClipMainWidget)
{
    ui->setupUi(this);

    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->drawButton->setEnabled(false);

    connect(this, &PolygonClipMainWidget::send_grid_width, ui->widget, &PolygonGraphWidget::onGridWidthChanged);

    connect(this, &PolygonClipMainWidget::reset_shape, ui->widget, &PolygonGraphWidget::onResetClicked);

    connect(ui->widget, &PolygonGraphWidget::send_time, this, &PolygonClipMainWidget::onTimePassed);

    connect(ui->widget, &PolygonGraphWidget::set_draw_status, this, &PolygonClipMainWidget::setDrawButtonStatus);

    connect(ui->widget, &PolygonGraphWidget::update_progress, this, &PolygonClipMainWidget::setProgressUpdate);

    connect(ui->drawPolygonButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::drawPolygon);

    connect(ui->drawArtifactButton, &QPushButton::clicked, ui->widget, &PolygonClipGraphWidget::drawArtifact);

    connect(ui->drawButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::polygonOperation);

    connect(this, &PolygonClipMainWidget::send_XY, ui->widget, &PolygonClipGraphWidget::translateXYChanged);

    on_gridWidth_valueChanged(5);
}

PolygonClipMainWidget::~PolygonClipMainWidget()
{
    delete ui;
}

void PolygonClipMainWidget::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(480 / 2 / arg1) - 1,
           dim = 2 * arg1 * x - 1;
    ui->widget->setFixedSize(dim, dim);
    emit send_grid_width(arg1);
    this->on_resetButton_clicked();
}

void PolygonClipMainWidget::on_resetButton_clicked()
{
    ui->drawButton->setEnabled(false);
    ui->drawArtifactButton->setEnabled(false);
    ui->drawPolygonButton->setEnabled(true);
    ui->gridWidth->setEnabled(true);
    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    emit reset_shape();
}

void PolygonClipMainWidget::setDrawButtonStatus(QString, bool status, bool showTime)
{
    ui->drawButton->setEnabled(status);
    ui->drawArtifactButton->setEnabled(status);
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

void PolygonClipMainWidget::onTimePassed(QString, qint64 t)
{
    ui->timeDisplay->setPlainText(QString::number(t) + "\u03BCs");
}

void PolygonClipMainWidget::setProgressUpdate(QString, int value)
{
    if (!ui->progressBar->isVisible())
        ui->progressBar->setVisible(true);
    ui->progressBar->setValue(value);
}

void PolygonClipMainWidget::on_spinBox_valueChanged(int)
{
    emit send_XY(QPoint(ui->spinBox->value(), ui->spinBox_2->value()));
}

void PolygonClipMainWidget::on_spinBox_2_valueChanged(int)
{
    emit send_XY(QPoint(ui->spinBox->value(), ui->spinBox_2->value()));
}
