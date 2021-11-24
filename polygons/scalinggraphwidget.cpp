#include "scalinggraphwidget.h"

ScalingGraphWidget::ScalingGraphWidget(QWidget *parent)
    : PolygonGraphWidget(parent), p(QPointF(1, 1))
{
}

void ScalingGraphWidget::scaleXYChanged(const QPointF &p)
{
    this->p = p;
}

void ScalingGraphWidget::performOperation()
{
    QList<QPoint> newSelected;
    foreach (auto pp, selected)
        newSelected.append(QPoint(pp.x() * p.x(), pp.y() * p.y()));
    for (auto i = 0; i < newSelected.count(); i++)
    {
        auto t = newSelected.at(i), t2 = newSelected.at((i + 1) % newSelected.count());
        x.setCoordinates(t.x(), t.y(), t2.x(), t2.y());
        const QVector<QPoint> p = x.drawLine();
        foreach(QPoint point, p)
            editPixMap(point, qMakePair(true, false));
    }
}
