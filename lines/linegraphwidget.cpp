#include "linegraphwidget.h"

#include <chrono>

LineGraphWidget::LineGraphWidget(QWidget *parent)
    : GraphWidget(parent), x1(0), y1(0), x2(0), y2(0)
{
}

void LineGraphWidget::onDataPassed(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->m_shape = true;
    this->repaint();
}

void LineGraphWidget::drawShape(QPainter &painter)
{
    quint64 t0, t1;
    t0 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    this->drawLine(painter);
    t1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    emit send_time(this->objectName(), t1 - t0);
}
