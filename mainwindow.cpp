#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->menubar, &QMenuBar::triggered, this, &MainWindow::menu_item_clicked);

    // Set defaults
    ui->stackedWidget->removeWidget(ui->page_2);
    ui->menu2D_Clipping->menuAction()->setVisible(false);
    ui->menu2D_Scan_conversion_polygon_filling->menuAction()->setVisible(false);
    ui->menu2D_Transformations->menuAction()->setVisible(false);
    ui->menu3D_Graphics->menuAction()->setVisible(false);
    ui->menuCurves->menuAction()->setVisible(false);
    ui->menuProjection->menuAction()->setVisible(false);

    ui->actionCircles->setVisible(false);
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

void MainWindow::menu_item_clicked(QAction *)
{
//    TODO: When changed set appropriate index on click
//    ui->stackedWidget->setCurrentIndex(1);
}
