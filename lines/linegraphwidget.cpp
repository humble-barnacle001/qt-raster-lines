#include "linegraphwidget.h"

#include <chrono>
#include <QMap>

LineGraphWidget::LineGraphWidget(QWidget *parent)
    : GraphWidget(parent), x1(0), y1(0), x2(0), y2(0)
{
}

void LineGraphWidget::setCoordinates(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

void LineGraphWidget::onDataPassed(int x1, int y1, int x2, int y2)
{
    this->setCoordinates(x1, y1, x2, y2);
    this->m_shape = true;
    this->animateDraw();
}

const GraphWidget::CustomPairList LineGraphWidget::drawShape()
{
    quint64 t0, t1;
    t0 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    const auto y = this->drawLine();
    GraphWidget::CustomPairList x;
    for (auto i = 0; i < y.count(); i++)
        x.append(qMakePair(y.at(i), Qt::darkBlue));

    t1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    emit send_time(this->objectName(), t1 - t0);

    return x;
}
