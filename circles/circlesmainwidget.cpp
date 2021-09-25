#include "circlesmainwidget.h"
#include "ui_circlesmainwidget.h"

CirclesMainWidget::CirclesMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CirclesMainWidget)
{
    ui->setupUi(this);
}

CirclesMainWidget::~CirclesMainWidget()
{
    delete ui;
}

void CirclesMainWidget::on_algoSelector_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

