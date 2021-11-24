#include "lineclipgraphwidget.h"

LineClipGraphWidget::LineClipGraphWidget(QWidget *parent)
    : PolygonGraphWidget(parent), line(2),
      mx(1), my(1),
      a(QPoint(0, 0)), b(QPoint(0, 0))
{
}

void LineClipGraphWidget::translateXYChanged(const QPoint &p)
{
    this->mx = p.x();
    this->my = p.y();
}

void LineClipGraphWidget::drawPolygon(bool)
{
    line = 2;
    selected = {QPoint(0, 0), QPoint(mx, 0), QPoint(mx, my), QPoint(0, my)};
    PolygonGraphWidget::drawPolygon();
}

void LineClipGraphWidget::onPointSelected(const QPoint &p)
{
    if (line > 0)
    {
        if (line == 1)
        {
            b = p;
            x.setCoordinates(a.x(), a.y(), b.x(), b.y());
            lp = x.drawLine();
            foreach (QPoint pp, lp)
                updateDefaultPoints(qMakePair(pp, Qt::yellow));
        }
        else
        {
            a = p;
            updateDefaultPoints(qMakePair(p, Qt::yellow));
        }
        line--;
    }
    else
    {
    }
}

void LineClipGraphWidget::onResetClicked()
{
    line = 2;
    PolygonGraphWidget::onResetClicked();
}

void LineClipGraphWidget::performOperation()
{
    bool ct = true;
    foreach (auto p, lp)
    {
        if (p.x() <= mx && p.y() <= my && p.x() >= 0 && p.y() >= 0)
        {
            editPixMap(p, qMakePair(true, false));
            ct = false;
        }
    }
    if (ct)
        editPixMap(QPoint(0, 0), qMakePair(true, false));
}