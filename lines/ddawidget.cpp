#include "ddawidget.h"

#include <QPainter>

void DDAWidget::drawLine(QPainter &qp)
{
    QColor qc(Qt::darkBlue);
    qp.setPen(qc);
    qreal dx = x2 - x1, dy = y2 - y1;
    qreal step = abs(dx) >= abs(dy) ? abs(dx) : abs(dy);
    dx = dx/step;
    dy = dy/step;
    qreal x = this->x1, y = this->y1, i =1;
    const QPoint center = resolveCoordinates(0,0);
    while(i<=step+1){
        this->drawPoint(qp, center, resolveCoordinates(x, y), qc);
        x+=dx;
        y+=dy;
        i++;
    }
}
