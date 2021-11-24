#include "ellipsesmainwidget.h"
#include "ui_ellipsesmainwidget.h"

EllipsesMainWidget::EllipsesMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EllipsesMainWidget)
{
    ui->setupUi(this);
}

EllipsesMainWidget::~EllipsesMainWidget()
{
    delete ui;
}
