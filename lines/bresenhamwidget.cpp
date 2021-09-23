#include "bresenhamwidget.h"

#include <QPainter>
#include <cmath>

void BresenhamWidget::drawLine(QPainter &painter)
{
    QColor penColor(Qt::darkBlue);
    painter.setPen(penColor);
    int dx = x2 - x1, dy = y2 - y1, x, y, xf, yf, p = 0;
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
            this->drawPoint(painter, QPoint(x, y), penColor);
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
            this->drawPoint(painter, QPoint(x, y), penColor);
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
}
