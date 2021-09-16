#include "linegraphwidget.h"

LineGraphWidget::LineGraphWidget(QWidget *parent)
    : GraphWidget(parent)
    , x1(0), y1(0), x2(0), y2(0)
{}


void LineGraphWidget::onDataPassed(int x1, int y1, int x2, int y2)
{
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
    this->m_shape=true;
    this->repaint();
}
