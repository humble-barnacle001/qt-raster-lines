#include "translationmainwidget.h"
#include "ui_translationmainwidget.h"

TranslationMainWidget::TranslationMainWidget(QWidget *parent) : QWidget(parent),
                                                                ui(new Ui::TranslationMainWidget)
{
    ui->setupUi(this);

    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->drawButton->setEnabled(false);

    connect(this, &TranslationMainWidget::send_grid_width, ui->widget, &PolygonGraphWidget::onGridWidthChanged);

    connect(this, &TranslationMainWidget::reset_shape, ui->widget, &PolygonGraphWidget::onResetClicked);

    connect(ui->widget, &PolygonGraphWidget::send_time, this, &TranslationMainWidget::onTimePassed);

    connect(ui->widget, &PolygonGraphWidget::set_draw_status, this, &TranslationMainWidget::setDrawButtonStatus);

    connect(ui->widget, &PolygonGraphWidget::update_progress, this, &TranslationMainWidget::setProgressUpdate);

    connect(ui->drawPolygonButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::drawPolygon);

    connect(ui->drawButton, &QPushButton::clicked, ui->widget, &PolygonGraphWidget::polygonOperation);

    connect(this, &TranslationMainWidget::send_XY, ui->widget, &TranslationGraphWidget::translateXYChanged);

    on_gridWidth_valueChanged(5);
}

TranslationMainWidget::~TranslationMainWidget()
{
    delete ui;
}

void TranslationMainWidget::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(480 / 2 / arg1) - 1,
           dim = 2 * arg1 * x - 1;
    ui->widget->setFixedSize(dim, dim);
    emit send_grid_width(arg1);
    this->on_resetButton_clicked();
}

void TranslationMainWidget::on_resetButton_clicked()
{
    ui->drawButton->setEnabled(false);
    ui->drawPolygonButton->setEnabled(true);
    ui->gridWidth->setEnabled(true);
    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    emit reset_shape();
}

void TranslationMainWidget::setDrawButtonStatus(QString, bool status, bool showTime)
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

void TranslationMainWidget::onTimePassed(QString, qint64 t)
{
    ui->timeDisplay->setPlainText(QString::number(t) + "\u03BCs");
}

void TranslationMainWidget::setProgressUpdate(QString, int value)
{
    if (!ui->progressBar->isVisible())
        ui->progressBar->setVisible(true);
    ui->progressBar->setValue(value);
}

void TranslationMainWidget::on_spinBox_valueChanged(int)
{
    emit send_XY(QPoint(ui->spinBox->value(), ui->spinBox_2->value()));
}

void TranslationMainWidget::on_spinBox_2_valueChanged(int)
{
    emit send_XY(QPoint(ui->spinBox->value(), ui->spinBox_2->value()));
}
