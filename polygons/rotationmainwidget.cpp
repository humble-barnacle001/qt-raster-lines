#include "rotationmainwidget.h"
#include "ui_rotationmainwidget.h"

RotationMainWidget::RotationMainWidget(QWidget *parent) : QWidget(parent),
                                                          ui(new Ui::RotationMainWidget)
{
    ui->setupUi(this);

    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->drawButton->setEnabled(false);

    connect(this, &RotationMainWidget::send_grid_width, ui->widget, &PolygonGraphWidget::onGridWidthChanged);

    connect(this, &RotationMainWidget::reset_shape, ui->widget, &PolygonGraphWidget::onResetClicked);

    connect(ui->widget, &PolygonGraphWidget::send_time, this, &RotationMainWidget::onTimePassed);

    connect(ui->widget, &PolygonGraphWidget::set_draw_status, this, &RotationMainWidget::setDrawButtonStatus);

    connect(ui->widget, &PolygonGraphWidget::update_progress, this, &RotationMainWidget::setProgressUpdate);

    connect(ui->drawPolygonButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::drawPolygon);

    connect(ui->drawButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::polygonOperation);

    connect(this, &RotationMainWidget::send_angle, ui->widget, &RotationGraphWidget::angleChanged);

    on_gridWidth_valueChanged(5);
}

RotationMainWidget::~RotationMainWidget()
{
    delete ui;
}

void RotationMainWidget::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(480 / 2 / arg1) - 1,
           dim = 2 * arg1 * x - 1;
    ui->widget->setFixedSize(dim, dim);
    emit send_grid_width(arg1);
    this->on_resetButton_clicked();
}

void RotationMainWidget::on_resetButton_clicked()
{
    ui->drawButton->setEnabled(false);
    ui->drawPolygonButton->setEnabled(true);
    ui->gridWidth->setEnabled(true);
    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    emit reset_shape();
}

void RotationMainWidget::setDrawButtonStatus(QString, bool status, bool showTime)
{
    ui->drawButton->setEnabled(status);
    ui->drawPolygonButton->setEnabled(status);
    ui->gridWidth->setEnabled(status);
    ui->resetButton->setEnabled(status);
    ui->spinBox->setEnabled(status);
    if (showTime)
    {
        ui->timeDisplay->setVisible(status);
        ui->progressBar->setVisible(status);
    }
}

void RotationMainWidget::onTimePassed(QString, qint64 t)
{
    ui->timeDisplay->setPlainText(QString::number(t) + "\u03BCs");
}

void RotationMainWidget::setProgressUpdate(QString, int value)
{
    if (!ui->progressBar->isVisible())
        ui->progressBar->setVisible(true);
    ui->progressBar->setValue(value);
}

void RotationMainWidget::on_spinBox_valueChanged(int arg1)
{
    emit send_angle(arg1);
}
