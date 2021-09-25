#include "bresenhamwidget.h"

#include <cmath>

const QList<QPoint> BresenhamWidget::drawLine()
{
    int dx = x2 - x1, dy = y2 - y1, x, y, xf, yf, p = 0;
    QList<QPoint> points;
    if (std::abs(dx) >= std::abs(dy))
    {
        if (x1 <= x2)
        {
            x = x1;
            y = y1;
            xf = x2;
        }
        else
        {
            x = x2;
            y = y2;
            xf = x1;
            dx = -dx;
            dy = -dy;
        }

        while (x <= xf)
        {
            points.append(QPoint(x, y));
            p += dy;
            if ((p << 1) >= dx)
            {
                y++;
                p -= dx;
            }
            else if (-(p << 1) >= dx)
            {
                y--;
                p += dx;
            }
            x++;
        }
    }
    else
    {
        if (y1 <= y2)
        {
            y = y1;
            x = x1;
            yf = y2;
        }
        else
        {
            y = y2;
            x = x2;
            yf = y1;
            dy = -dy;
            dx = -dx;
        }
        while (y <= yf)
        {
            points.append(QPoint(x, y));
            p += dx;
            if ((p << 1) >= dy)
            {
                x++;
                p -= dy;
            }
            else if (-(p << 1) >= dy)
            {
                x--;
                p += dy;
            }
            y++;
        }
    }
    return points;
}
