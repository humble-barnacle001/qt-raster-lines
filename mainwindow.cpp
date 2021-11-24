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

//    ui->menu2D_Clipping->menuAction()->setVisible(false);
    ui->menu3D_Graphics->menuAction()->setVisible(false);
    ui->menuCurves->menuAction()->setVisible(false);
    ui->menuProjection->menuAction()->setVisible(false);

    ui->actionEllipses->setVisible(false);
    ui->actionLiang_Barsky->setVisible(false);
    ui->actionWeiler_Atherton->setVisible(false);
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
    ui->textEdit->setText(action->text());
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
    else if (actionName == "actionTranslation")
        ui->stackedWidget->setCurrentIndex(3);
    else if (actionName == "actionRotation")
        ui->stackedWidget->setCurrentIndex(4);
    else if (actionName == "actionScaling")
        ui->stackedWidget->setCurrentIndex(5);
    else if (actionName == "actionShear")
        ui->stackedWidget->setCurrentIndex(6);
    else if (actionName == "actionReflection")
        ui->stackedWidget->setCurrentIndex(7);
    else if (actionName == "actionCohen_Sutherland")
        ui->stackedWidget->setCurrentIndex(8);
    else if (actionName == "actionSutherland_Hodgeman")
        ui->stackedWidget->setCurrentIndex(9);
}
