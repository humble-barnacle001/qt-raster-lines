#include "bresenhammidpointcirclewidget.h"

BresenhamMidpointCircleWidget::BresenhamMidpointCircleWidget() {}

const QList<QPoint> BresenhamMidpointCircleWidget::drawCircle()
{
    QList<QPoint> points;
    points.append(QPoint(cx, cy));
    qint32 x = 0, y = r, d = 3 - (r << 1);
    points.append(eightWaySymmetric(x, y));

    while (x <= y)
    {
        if (d <= 0)
            d += (x << 2) + 6;
        else
        {
            d += (x << 2) - (y << 2) + 10;
            // d += (x << 2) - (y << 2) + 1;
            y--;
        }
        x++;
        points.append(eightWaySymmetric(x, y));
    }

    return points;
}