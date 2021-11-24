#include "reflectionmainwidget.h"
#include "ui_reflectionmainwidget.h"

ReflectionMainWidget::ReflectionMainWidget(QWidget *parent) : QWidget(parent),
                                                              ui(new Ui::ReflectionMainWidget)
{
    ui->setupUi(this);

    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->drawButton->setEnabled(false);

    connect(this, &ReflectionMainWidget::send_grid_width, ui->widget, &PolygonGraphWidget::onGridWidthChanged);

    connect(this, &ReflectionMainWidget::reset_shape, ui->widget, &PolygonGraphWidget::onResetClicked);

    connect(ui->widget, &PolygonGraphWidget::send_time, this, &ReflectionMainWidget::onTimePassed);

    connect(ui->widget, &PolygonGraphWidget::set_draw_status, this, &ReflectionMainWidget::setDrawButtonStatus);

    connect(ui->widget, &PolygonGraphWidget::update_progress, this, &ReflectionMainWidget::setProgressUpdate);

    connect(ui->drawPolygonButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::drawPolygon);

    connect(ui->drawButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::polygonOperation);

    connect(this, &ReflectionMainWidget::line_select, ui->widget, &ReflectionGraphWidget::lineSelected);

    connect(ui->widget, &PolygonGraphWidget::set_fillButton_status, this, &ReflectionMainWidget::setLineButtonStatus);

    on_gridWidth_valueChanged(5);
}

ReflectionMainWidget::~ReflectionMainWidget()
{
    delete ui;
}

void ReflectionMainWidget::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(480 / 2 / arg1) - 1,
           dim = 2 * arg1 * x - 1;
    ui->widget->setFixedSize(dim, dim);
    emit send_grid_width(arg1);
    this->on_resetButton_clicked();
}

void ReflectionMainWidget::on_resetButton_clicked()
{
    ui->drawButton->setEnabled(false);
    ui->drawPolygonButton->setEnabled(true);
    ui->lineButton->setEnabled(false);
    ui->gridWidth->setEnabled(true);
    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    emit reset_shape();
}

void ReflectionMainWidget::setDrawButtonStatus(QString, bool status, bool showTime)
{
    ui->drawButton->setEnabled(status);
    ui->drawPolygonButton->setEnabled(status);
    ui->lineButton->setEnabled(status);
    ui->gridWidth->setEnabled(status);
    ui->resetButton->setEnabled(status);
    if (showTime)
    {
        ui->timeDisplay->setVisible(status);
        ui->progressBar->setVisible(status);
    }
}

void ReflectionMainWidget::setLineButtonStatus(bool status)
{
    ui->lineButton->setEnabled(status);
}

void ReflectionMainWidget::onTimePassed(QString, qint64 t)
{
    ui->timeDisplay->setPlainText(QString::number(t) + "\u03BCs");
}

void ReflectionMainWidget::setProgressUpdate(QString, int value)
{
    if (!ui->progressBar->isVisible())
        ui->progressBar->setVisible(true);
    ui->progressBar->setValue(value);
}

void ReflectionMainWidget::on_lineButton_clicked()
{
    emit line_select();
}
