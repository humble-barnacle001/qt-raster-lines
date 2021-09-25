#include "ddawidget.h"

#include <cmath>

const QList<QPoint> DDAWidget::drawLine()
{
    qreal dx = x2 - x1, dy = y2 - y1;
    qreal step = abs(dx) >= abs(dy) ? abs(dx) : abs(dy);
    dx = dx / step;
    dy = dy / step;
    qreal x = this->x1, y = this->y1, i = 1;
    QList<QPoint> points;
    while (i <= step + 1)
    {
        points.append(QPoint(std::round(x), std::round(y)));
        x += dx;
        y += dy;
        i++;
    }
    return points;
}
