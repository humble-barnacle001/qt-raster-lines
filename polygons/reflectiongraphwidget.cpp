#include "reflectiongraphwidget.h"

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

ReflectionGraphWidget::ReflectionGraphWidget(QWidget *parent)
    : PolygonGraphWidget(parent), line(-1)
{
}

void ReflectionGraphWidget::lineSelected()
{
    this->line = 1;
}

void ReflectionGraphWidget::onPointSelected(const QPoint &p)
{
    if (line >= 0)
    {
        if (line == 0)
        {
            b = p;
            x.setCoordinates(a.x(), a.y(), b.x(), b.y());
            const QList<QPoint> t = x.drawLine();
            foreach (QPoint pp, t)
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
        PolygonGraphWidget::onPointSelected(p);
}

void ReflectionGraphWidget::onResetClicked()
{
    line = -1;
    PolygonGraphWidget::onResetClicked();
}

void ReflectionGraphWidget::drawPolygon(bool)
{
    PolygonGraphWidget::drawPolygon();
    if (selected.count() > 2)
        emit set_fillButton_status(true);
}

void ReflectionGraphWidget::performOperation()
{
    double rad = -std::atan((1.0 * b.y() - a.y()) / (1.0 * b.x() - a.x()));
    int tx = -a.x(), ty = -a.y();
    QList<QPoint> newSelected;

    foreach (auto pp, selected)
    {
        double x = pp.x(), y = pp.y(), x1, x2, x3, x4, x5, y1, y2, y3, y4, y5;
        x1 = x + tx;
        y1 = y + ty;
        x2 = x1 * std::cos(rad) - y1 * std::sin(rad);
        y2 = x1 * std::sin(rad) + y1 * std::cos(rad);
        x3 = x2;
        y3 = -y2;
        x4 = x3 * std::cos(rad) + y3 * std::sin(rad);
        y4 = -x3 * std::sin(rad) + y3 * std::cos(rad);
        x5 = x4 - tx;
        y5 = y4 - ty;

        newSelected.append(QPoint(std::round(x5), std::round(y5)));
    }
    for (auto i = 0; i < newSelected.count(); i++)
    {
        auto t = newSelected.at(i), t2 = newSelected.at((i + 1) % newSelected.count());
        x.setCoordinates(t.x(), t.y(), t2.x(), t2.y());
        const QVector<QPoint> p = x.drawLine();
        foreach (QPoint point, p)
            editPixMap(point, qMakePair(true, false));
    }
}
