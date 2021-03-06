#include "polarcirclewidget.h"

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

PolarCircleWidget::PolarCircleWidget() {}

const QList<QPoint> PolarCircleWidget::drawCircle()
{
    QList<QPoint> points;
    qreal theta = 0, step = 1.0 / r;
    points.append(QPoint(cx, cy));
    while (theta <= 2 * M_PI)
    {
        points.append(QPoint(std::round(cx + r * std::cos(theta)), std::round(cy + r * std::sin(theta))));
        theta += step;
    }
    return points;
}