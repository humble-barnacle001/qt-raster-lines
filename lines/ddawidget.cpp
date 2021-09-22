#include "ddawidget.h"

#include <QPainter>

void DDAWidget::drawLine(QPainter &painter)
{
    QColor penColor(Qt::darkBlue);
    painter.setPen(penColor);
    qreal dx = x2 - x1, dy = y2 - y1;
    qreal step = abs(dx) >= abs(dy) ? abs(dx) : abs(dy);
    dx = dx / step;
    dy = dy / step;
    qreal x = this->x1, y = this->y1, i = 1;
    while (i <= step + 1)
    {
        this->drawPoint(painter, QPoint(x, y), penColor);
        x += dx;
        y += dy;
        i++;
    }
}
