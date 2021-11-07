#include "polygonmainwidget.h"
#include "ui_polygonmainwidget.h"

PolygonMainWidget::PolygonMainWidget(QWidget *parent) : QWidget(parent),
                                                        ui(new Ui::PolygonMainWidget)
{
    ui->setupUi(this);

    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->drawButton->setEnabled(false);

    connect(this, &PolygonMainWidget::send_grid_width, ui->page_0, &PolygonGraphWidget::onGridWidthChanged);
    connect(this, &PolygonMainWidget::reset_shape, ui->page_0, &PolygonGraphWidget::onResetClicked);
    connect(this, &PolygonMainWidget::send_grid_width, ui->page_1, &PolygonGraphWidget::onGridWidthChanged);
    connect(this, &PolygonMainWidget::reset_shape, ui->page_1, &PolygonGraphWidget::onResetClicked);
    connect(this, &PolygonMainWidget::send_grid_width, ui->page_2, &PolygonGraphWidget::onGridWidthChanged);
    connect(this, &PolygonMainWidget::reset_shape, ui->page_2, &PolygonGraphWidget::onResetClicked);

    // Default page
    change_widget(0);

    on_gridWidth_valueChanged(5);
}

PolygonMainWidget::~PolygonMainWidget()
{
    delete ui;
}

void PolygonMainWidget::change_widget(int index)
{
    qDebug("Change %d", index);
    switch (index)
    {
    case 0:
        connect(ui->page_0, &PolygonGraphWidget::send_time, this, &PolygonMainWidget::onTimePassed);
        connect(ui->page_0, &PolygonGraphWidget::set_draw_status, this, &PolygonMainWidget::setDrawButtonStatus);
        connect(ui->page_0, &PolygonGraphWidget::update_progress, this, &PolygonMainWidget::setProgressUpdate);
        connect(ui->drawPolygonButton, &QPushButton::clicked, ui->page_0, &PolygonGraphWidget::drawPolygon);
        connect(ui->drawButton, &QPushButton::clicked, ui->page_0, &PolygonGraphWidget::polygonOperation);

        disconnect(ui->page_1, &PolygonGraphWidget::send_time, this, &PolygonMainWidget::onTimePassed);
        disconnect(ui->page_1, &PolygonGraphWidget::set_draw_status, this, &PolygonMainWidget::setDrawButtonStatus);
        disconnect(ui->page_1, &PolygonGraphWidget::update_progress, this, &PolygonMainWidget::setProgressUpdate);
        disconnect(ui->drawPolygonButton, &QPushButton::clicked, ui->page_1, &PolygonGraphWidget::drawPolygon);
        disconnect(ui->drawButton, &QPushButton::clicked, ui->page_1, &PolygonGraphWidget::polygonOperation);

        disconnect(ui->page_2, &PolygonGraphWidget::send_time, this, &PolygonMainWidget::onTimePassed);
        disconnect(ui->page_2, &PolygonGraphWidget::set_draw_status, this, &PolygonMainWidget::setDrawButtonStatus);
        disconnect(ui->page_2, &PolygonGraphWidget::update_progress, this, &PolygonMainWidget::setProgressUpdate);
        disconnect(ui->drawPolygonButton, &QPushButton::clicked, ui->page_2, &PolygonGraphWidget::drawPolygon);
        disconnect(ui->drawButton, &QPushButton::clicked, ui->page_2, &PolygonGraphWidget::polygonOperation);

        ui->seedButton->setVisible(false);
        break;

    case 1:
        disconnect(ui->page_0, &PolygonGraphWidget::send_time, this, &PolygonMainWidget::onTimePassed);
        disconnect(ui->page_0, &PolygonGraphWidget::set_draw_status, this, &PolygonMainWidget::setDrawButtonStatus);
        disconnect(ui->page_0, &PolygonGraphWidget::update_progress, this, &PolygonMainWidget::setProgressUpdate);
        disconnect(ui->drawPolygonButton, &QPushButton::clicked, ui->page_0, &PolygonGraphWidget::drawPolygon);
        disconnect(ui->drawButton, &QPushButton::clicked, ui->page_0, &PolygonGraphWidget::polygonOperation);

        connect(ui->page_1, &PolygonGraphWidget::send_time, this, &PolygonMainWidget::onTimePassed);
        connect(ui->page_1, &PolygonGraphWidget::set_draw_status, this, &PolygonMainWidget::setDrawButtonStatus);
        connect(ui->page_1, &PolygonGraphWidget::update_progress, this, &PolygonMainWidget::setProgressUpdate);
        connect(ui->drawPolygonButton, &QPushButton::clicked, ui->page_1, &PolygonGraphWidget::drawPolygon);
        connect(ui->drawButton, &QPushButton::clicked, ui->page_1, &PolygonGraphWidget::polygonOperation);
        connect(this, &PolygonMainWidget::select_seed, ui->page_1, &PolygonGraphWidget::selectSeed);
        connect(ui->page_1, &PolygonGraphWidget::set_fillButton_status, this, &PolygonMainWidget::setFillStatus);

        disconnect(ui->page_2, &PolygonGraphWidget::send_time, this, &PolygonMainWidget::onTimePassed);
        disconnect(ui->page_2, &PolygonGraphWidget::set_draw_status, this, &PolygonMainWidget::setDrawButtonStatus);
        disconnect(ui->page_2, &PolygonGraphWidget::update_progress, this, &PolygonMainWidget::setProgressUpdate);
        disconnect(ui->drawPolygonButton, &QPushButton::clicked, ui->page_2, &PolygonGraphWidget::drawPolygon);
        disconnect(ui->drawButton, &QPushButton::clicked, ui->page_2, &PolygonGraphWidget::polygonOperation);
        disconnect(this, &PolygonMainWidget::select_seed, ui->page_2, &PolygonGraphWidget::selectSeed);
        disconnect(ui->page_2, &PolygonGraphWidget::set_fillButton_status, this, &PolygonMainWidget::setFillStatus);

        ui->seedButton->setVisible(true);
        break;

    case 2:
        disconnect(ui->page_0, &PolygonGraphWidget::send_time, this, &PolygonMainWidget::onTimePassed);
        disconnect(ui->page_0, &PolygonGraphWidget::set_draw_status, this, &PolygonMainWidget::setDrawButtonStatus);
        disconnect(ui->page_0, &PolygonGraphWidget::update_progress, this, &PolygonMainWidget::setProgressUpdate);
        disconnect(ui->drawPolygonButton, &QPushButton::clicked, ui->page_0, &PolygonGraphWidget::drawPolygon);
        disconnect(ui->drawButton, &QPushButton::clicked, ui->page_0, &PolygonGraphWidget::polygonOperation);

        disconnect(ui->page_1, &PolygonGraphWidget::send_time, this, &PolygonMainWidget::onTimePassed);
        disconnect(ui->page_1, &PolygonGraphWidget::set_draw_status, this, &PolygonMainWidget::setDrawButtonStatus);
        disconnect(ui->page_1, &PolygonGraphWidget::update_progress, this, &PolygonMainWidget::setProgressUpdate);
        disconnect(ui->drawPolygonButton, &QPushButton::clicked, ui->page_1, &PolygonGraphWidget::drawPolygon);
        disconnect(ui->drawButton, &QPushButton::clicked, ui->page_1, &PolygonGraphWidget::polygonOperation);
        disconnect(this, &PolygonMainWidget::select_seed, ui->page_1, &PolygonGraphWidget::selectSeed);
        disconnect(ui->page_1, &PolygonGraphWidget::set_fillButton_status, this, &PolygonMainWidget::setFillStatus);

        connect(ui->page_2, &PolygonGraphWidget::send_time, this, &PolygonMainWidget::onTimePassed);
        connect(ui->page_2, &PolygonGraphWidget::set_draw_status, this, &PolygonMainWidget::setDrawButtonStatus);
        connect(ui->page_2, &PolygonGraphWidget::update_progress, this, &PolygonMainWidget::setProgressUpdate);
        connect(ui->drawPolygonButton, &QPushButton::clicked, ui->page_2, &PolygonGraphWidget::drawPolygon);
        connect(ui->drawButton, &QPushButton::clicked, ui->page_2, &PolygonGraphWidget::polygonOperation);
        connect(this, &PolygonMainWidget::select_seed, ui->page_2, &PolygonGraphWidget::selectSeed);
        connect(ui->page_2, &PolygonGraphWidget::set_fillButton_status, this, &PolygonMainWidget::setFillStatus);

        ui->seedButton->setVisible(true);
        break;

    default:
        break;
    }

    QVector<QString> fillList = {"ScanLine Fill", "Boundary Fill", "Flood Fill"};

    ui->drawButton->setText(fillList[index]);
    ui->drawButton->setEnabled(false);
    ui->stackedWidget->setCurrentIndex(index % ui->stackedWidget->count());
}

void PolygonMainWidget::on_gridWidth_valueChanged(int arg1)
{
    qint32 x = std::ceil(480 / 2 / arg1) - 1,
           dim = 2 * arg1 * x - 1;
    ui->stackedWidget->setFixedSize(dim, dim);
    emit send_grid_width(arg1);
    this->on_resetButton_clicked();
}

void PolygonMainWidget::on_resetButton_clicked()
{
    ui->drawButton->setEnabled(false);
    ui->drawPolygonButton->setEnabled(true);
    ui->gridWidth->setEnabled(true);
    ui->timeDisplay->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->seedButton->setEnabled(false);
    emit reset_shape();
}

void PolygonMainWidget::setDrawButtonStatus(QString, bool status, bool showTime)
{
    ui->seedButton->setEnabled(status);
    ui->drawButton->setEnabled(status);
    ui->drawPolygonButton->setEnabled(status);
    ui->gridWidth->setEnabled(status);
    ui->resetButton->setEnabled(status);
    if (showTime)
    {
        ui->timeDisplay->setVisible(status);
        ui->progressBar->setVisible(status);
    }
}

void PolygonMainWidget::setFillStatus(bool status)
{
    ui->drawButton->setEnabled(status);
    ui->seedButton->setEnabled(!status);
}

void PolygonMainWidget::onTimePassed(QString, qint64 t)
{
    ui->timeDisplay->setPlainText(QString::number(t) + "\u03BCs");
}

void PolygonMainWidget::setProgressUpdate(QString, int value)
{
    if (!ui->progressBar->isVisible())
        ui->progressBar->setVisible(true);
    ui->progressBar->setValue(value);
}

void PolygonMainWidget::on_seedButton_clicked()
{
    emit select_seed();
}
