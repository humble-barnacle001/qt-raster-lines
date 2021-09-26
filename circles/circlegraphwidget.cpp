#include "circlegraphwidget.h"

#include <chrono>

CircleGraphWidget::CircleGraphWidget(QWidget *parent, qsizetype dim, quint32 timer)
    : GraphWidget(parent, dim, timer),
      cx(0), cy(0), r(0)
{
}

void CircleGraphWidget::onDataPassed(qint32 cx, qint32 cy, qint32 r)
{
    this->cx = cx;
    this->cy = cy;
    this->r = r;
    this->m_shape = true;
    this->animateDraw();
}

const QList<QPoint> CircleGraphWidget::eightWaySymmetric(qint32 x, qint32 y)
{
    QList<QPoint> points;
    points.append(QPoint(cx + x, cy + y));
    points.append(QPoint(cx + x, cy - y));
    points.append(QPoint(cx - x, cy - y));
    points.append(QPoint(cx - x, cy + y));
    points.append(QPoint(cx + y, cy + x));
    points.append(QPoint(cx + y, cy - x));
    points.append(QPoint(cx - y, cy - x));
    points.append(QPoint(cx - y, cy + x));

    return points;
}

const QList<QPoint> CircleGraphWidget::drawShape()
{
    quint64 t0, t1;
    t0 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    const auto x = this->drawCircle();

    t1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    emit send_time(this->objectName(), t1 - t0);

    return x;
}
