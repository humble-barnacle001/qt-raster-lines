#include "cartesiancirclewidget.h"

#define _USE_MATH_DEFINES
#include <cmath>

CartesianCircleWidget::CartesianCircleWidget() {}

const QList<QPoint> CartesianCircleWidget::drawCircle()
{
    QList<QPoint> points;
    points.append(QPoint(cx, cy));
    qreal t = r / std::sqrt(2);
    for (qreal x = -t, y = t; x <= t; x++, y = std::sqrt(1.0 * r * r - x * x))
    {
        points.append(QPoint(std::round(cx + x), std::round(cy + y)));
        points.append(QPoint(std::round(cx + x), std::round(cy - y)));
    }
    for (qreal y = -t, x = t; y <= t; y++, x = std::sqrt(1.0 * r * r - y * y))
    {
        points.append(QPoint(std::round(cx + x), std::round(cy + y)));
        points.append(QPoint(std::round(cx - x), std::round(cy + y)));
    }
    return points;
}