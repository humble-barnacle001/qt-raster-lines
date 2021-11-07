#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->menubar, &QMenuBar::triggered, this, &MainWindow::menu_item_clicked);
    connect(this, &MainWindow::polygon_change_widget, ui->page_3, &PolygonMainWidget::change_widget);

    // Set defaults
    ui->stackedWidget->setCurrentIndex(2);
    ui->textEdit->setText(QString("Scanline Fill"));

    ui->menu2D_Clipping->menuAction()->setVisible(false);
    ui->menu2D_Transformations->menuAction()->setVisible(false);
    ui->menu3D_Graphics->menuAction()->setVisible(false);
    ui->menuCurves->menuAction()->setVisible(false);
    ui->menuProjection->menuAction()->setVisible(false);

    ui->actionEllipses->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}

void MainWindow::menu_item_clicked(QAction *action)
{
    ui->textEdit->setText(    action->text());
    QString actionName = action->objectName();
    QVector<QString> PolygonFill = {"actionScanLine_Fill", "actionBoundary_Fill", "actionFlood_Fill"};
    //    TODO: When changed set appropriate index on click
    if (actionName == "actionLines")
        ui->stackedWidget->setCurrentIndex(0);
    else if (actionName == "actionCircles")
        ui->stackedWidget->setCurrentIndex(1);
    else if (PolygonFill.contains(actionName))
    {
        ui->stackedWidget->setCurrentIndex(2);
        emit polygon_change_widget(PolygonFill.indexOf(actionName));
    }
}
