#include "translationgraphwidget.h"

TranslationGraphWidget::TranslationGraphWidget(QWidget *parent)
    : PolygonGraphWidget(parent), p(QPoint(0, 0))
{
}

void TranslationGraphWidget::translateXYChanged(const QPoint &p)
{
    this->p = p;
}

void TranslationGraphWidget::performOperation()
{
    foreach (auto pp, polygon)
    {
        editPixMap(QPoint(pp.x() + p.x(), pp.y() + p.y()), qMakePair(true, false));
    }
}
