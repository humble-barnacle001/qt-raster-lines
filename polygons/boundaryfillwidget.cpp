#include "boundaryfillwidget.h"

BoundaryFillWidget::BoundaryFillWidget()
{
}

void BoundaryFillWidget::seedFill(const QPoint &p)
{
    QPair<bool, bool> curr = getPixMapAt(p);
    if (!curr.second && !curr.first)
    {
        editPixMap(p, qMakePair(true, false));
        addCustomPair(qMakePair(p, getFillColor()));
        seedFill(QPoint(p.x() + 1, p.y()));
        seedFill(QPoint(p.x() - 1, p.y()));
        seedFill(QPoint(p.x(), p.y() + 1));
        seedFill(QPoint(p.x(), p.y() - 1));
    }
}