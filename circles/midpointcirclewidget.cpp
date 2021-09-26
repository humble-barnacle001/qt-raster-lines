#include "midpointcirclewidget.h"

MidpointCircleWidget::MidpointCircleWidget() {}

const QList<QPoint> MidpointCircleWidget::drawCircle()
{
    QList<QPoint> points;
    points.append(QPoint(cx, cy));
    qint32 x = r, y = 0, d = 1 - r;
    points.append(eightWaySymmetric(x, y));

    while (x > y)
    {
        y++;
        if (d <= 0)
            d += (y << 2) + 1;
        else
        {
            d += (y << 2) - (x << 2) + 1;
            x--;
        }
        points.append(eightWaySymmetric(x, y));
    }

    return points;
}