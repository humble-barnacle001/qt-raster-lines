#include "cartesiancirclewidget.h"

#define _USE_MATH_DEFINES
#include <cmath>

CartesianCircleWidget::CartesianCircleWidget() {}

const QList<QPoint> CartesianCircleWidget::drawCircle()
{
    QList<QPoint> points;
    points.append(QPoint(cx, cy));
    for (qreal x = -r, y = 0; x <= r; x++, y = std::sqrt(1.0 * r * r - x * x))
    {
        points.append(QPoint(std::round(cx + x), std::round(cy + y)));
        points.append(QPoint(std::round(cx + x), std::round(cy - y)));
    }
    return points;
}