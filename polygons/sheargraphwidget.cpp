#include "sheargraphwidget.h"

ShearGraphWidget::ShearGraphWidget(QWidget *parent) : PolygonGraphWidget(parent), p(QPointF(0, 0))
{
}

void ShearGraphWidget::scaleXYChanged(const QPointF &p)
{
    this->p = p;
}

void ShearGraphWidget::performOperation()
{
    QList<QPoint> newSelected;
    foreach (auto pp, selected)
        newSelected.append(QPoint(pp.x() + pp.y() * p.x(), pp.y() + pp.x() * p.y()));
    for (auto i = 0; i < newSelected.count(); i++)
    {
        auto t = newSelected.at(i), t2 = newSelected.at((i + 1) % newSelected.count());
        x.setCoordinates(t.x(), t.y(), t2.x(), t2.y());
        const QVector<QPoint> p = x.drawLine();
        foreach (QPoint point, p)
            editPixMap(point, qMakePair(true, false));
    }
}