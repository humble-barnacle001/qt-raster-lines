#include "circlesmainwidget.h"
#include "ui_circlesmainwidget.h"

#include <cmath>

CirclesMainWidget::CirclesMainWidget(QWidget *parent) : QWidget(parent),
                                                        ui(new Ui::CirclesMainWidget)
{
    ui->setupUi(this);

    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);

    connect(this, &CirclesMainWidget::send_grid_width, ui->page_0, &PolarCircleWidget::onGridWidthChanged);
    connect(this, &CirclesMainWidget::reset_shape, ui->page_0, &PolarCircleWidget::onResetClicked);
    connect(this, &CirclesMainWidget::send_data, ui->page_0, &PolarCircleWidget::onDataPassed);
    connect(ui->page_0, &PolarCircleWidget::send_time, this, &CirclesMainWidget::onTimePassed);
    connect(ui->page_0, &PolarCircleWidget::set_draw_status, this, &CirclesMainWidget::setDrawButtonStatus);
    connect(ui->page_0, &GraphWidget::update_progress, this, &CirclesMainWidget::setProgressUpdate);

    connect(this, &CirclesMainWidget::send_grid_width, ui->page_1, &BresenhamMidpointCircleWidget::onGridWidthChanged);
    connect(this, &CirclesMainWidget::reset_shape, ui->page_1, &BresenhamMidpointCircleWidget::onResetClicked);
    connect(ui->page_1, &BresenhamMidpointCircleWidget::send_time, this, &CirclesMainWidget::onTimePassed);
    connect(ui->page_1, &BresenhamMidpointCircleWidget::set_draw_status, this, &CirclesMainWidget::setDrawButtonStatus);
    connect(ui->page_1, &GraphWidget::update_progress, this, &CirclesMainWidget::setProgressUpdate);

    connect(this, &CirclesMainWidget::send_grid_width, ui->page_2, &CartesianCircleWidget::onGridWidthChanged);
    connect(this, &CirclesMainWidget::reset_shape, ui->page_2, &CartesianCircleWidget::onResetClicked);
    connect(ui->page_2, &CartesianCircleWidget::send_time, this, &CirclesMainWidget::onTimePassed);
    connect(ui->page_2, &CartesianCircleWidget::set_draw_status, this, &CirclesMainWidget::setDrawButtonStatus);
    connect(ui->page_2, &GraphWidget::update_progress, this, &CirclesMainWidget::setProgressUpdate);

    connect(this, &CirclesMainWidget::send_grid_width, ui->page_3, &MidpointCircleWidget::onGridWidthChanged);
    connect(this, &CirclesMainWidget::reset_shape, ui->page_3, &MidpointCircleWidget::onResetClicked);
    connect(ui->page_3, &MidpointCircleWidget::send_time, this, &CirclesMainWidget::onTimePassed);
    connect(ui->page_3, &MidpointCircleWidget::set_draw_status, this, &CirclesMainWidget::setDrawButtonStatus);
    connect(ui->page_3, &GraphWidget::update_progress, this, &CirclesMainWidget::setProgressUpdate);
}

CirclesMainWidget::~CirclesMainWidget()
{
    delete ui;
}

void CirclesMainWidget::on_algoSelector_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    switch (index)
    {
    case 0:
        connect(this, &CirclesMainWidget::send_data, ui->page_0, &CircleGraphWidget::onDataPassed);
        disconnect(this, &CirclesMainWidget::send_data, ui->page_1, &CircleGraphWidget::onDataPassed);
        disconnect(this, &CirclesMainWidget::send_data, ui->page_2, &CircleGraphWidget::onDataPassed);
        disconnect(this, &CirclesMainWidget::send_data, ui->page_3, &CircleGraphWidget::onDataPassed);
        break;
    case 1:
        disconnect(this, &CirclesMainWidget::send_data, ui->page_0, &CircleGraphWidget::onDataPassed);
        connect(this, &CirclesMainWidget::send_data, ui->page_1, &CircleGraphWidget::onDataPassed);
        disconnect(this, &CirclesMainWidget::send_data, ui->page_2, &CircleGraphWidget::onDataPassed);
        disconnect(this, &CirclesMainWidget::send_data, ui->page_3, &CircleGraphWidget::onDataPassed);
        break;
    case 2:
        disconnect(this, &CirclesMainWidget::send_data, ui->page_0, &CircleGraphWidget::onDataPassed);
        disconnect(this, &CirclesMainWidget::send_data, ui->page_1, &CircleGraphWidget::onDataPassed);
        connect(this, &CirclesMainWidget::send_data, ui->page_2, &CircleGraphWidget::onDataPassed);
        disconnect(this, &CirclesMainWidget::send_data, ui->page_3, &CircleGraphWidget::onDataPassed);
        break;
    case 3:
        disconnect(this, &CirclesMainWidget::send_data, ui->page_0, &CircleGraphWidget::onDataPassed);
        disconnect(this, &CirclesMainWidget::send_data, ui->page_1, &CircleGraphWidget::onDataPassed);
        disconnect(this, &CirclesMainWidget::send_data, ui->page_2, &CircleGraphWidget::onDataPassed);
        connect(this, &CirclesMainWidget::send_data, ui->page_3, &CircleGraphWidget::onDataPassed);
        break;

    default:
        break;
    }
}

void CirclesMainWidget::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(480 / 2 / arg1) - 1,
           dim = 2 * arg1 * x - 1;
    ui->stackedWidget->setFixedSize(dim, dim);
    ui->cx->setMaximum(x - 1);
    ui->cy->setMaximum(x - 1);
    ui->r->setMaximum(x - 1);
    ui->cx->setMinimum(-x + 1);
    ui->cy->setMinimum(-x + 1);
    emit send_grid_width(arg1);
    this->on_resetButton_clicked();
}

void CirclesMainWidget::on_drawButton_clicked()
{
    emit send_data(ui->cx->value(), ui->cy->value(), ui->r->value());
    ui->progressBar->setVisible(true);
}

void CirclesMainWidget::on_resetButton_clicked()
{
    ui->cx->setValue(0);
    ui->cy->setValue(0);
    ui->r->setValue(0);
    ui->drawButton->setEnabled(true);
    ui->cx->setEnabled(true);
    ui->cy->setEnabled(true);
    ui->r->setEnabled(true);
    ui->algoSelector->setEnabled(true);
    ui->gridWidth->setEnabled(true);
    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    emit reset_shape();
}

void CirclesMainWidget::onTimePassed(QString, qint64 t)
{
    ui->timeDisplay->setPlainText(QString::number(t) + "\u03BCs");
}

void CirclesMainWidget::setDrawButtonStatus(QString, bool status)
{
    ui->drawButton->setEnabled(status);
    ui->algoSelector->setEnabled(status);
    ui->cx->setEnabled(status);
    ui->cy->setEnabled(status);
    ui->r->setEnabled(status);
    ui->gridWidth->setEnabled(status);
    ui->timeDisplay->setVisible(status);
}

void CirclesMainWidget::setProgressUpdate(QString, int value)
{
    ui->progressBar->setValue(value);
}
