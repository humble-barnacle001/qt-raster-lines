#include "polygonclipgraphwidget.h"

#include <QDebug>

PolygonClipGraphWidget::PolygonClipGraphWidget(QWidget *parent)
    : PolygonGraphWidget(parent), mx(1), my(1), y(nullptr)
{
}

void PolygonClipGraphWidget::translateXYChanged(const QPoint &p)
{
    this->mx = p.x();
    this->my = p.y();
}

void PolygonClipGraphWidget::drawPolygon(bool animate)
{
    onResetClicked();
    selected = {QPoint(0, 0), QPoint(mx, 0), QPoint(mx, my), QPoint(0, my)};
    PolygonGraphWidget::drawPolygon(animate);
}

void PolygonClipGraphWidget::drawArtifact()
{
    if (pv.count() < 2)
        return;
    foreach (auto point, pp)
        updateDefaultPoints(qMakePair(point, Qt::yellow), true, true);
    pp = {};
    for (auto i = 0; i < pv.count(); i++)
    {

        auto t = pv.at(i), t2 = pv.at((i + 1) % pv.count());
        x.setCoordinates(t.x(), t.y(), t2.x(), t2.y());
        const QVector<QPoint> p = x.drawLine();
        QSet<QPoint> pcpair;
        for (qsizetype i = 0; i < p.size(); i++)
        {
            auto point = p.at(i);
            pcpair.insert(point);
            updateDefaultPoints(qMakePair(point, Qt::yellow));
        }
        pp.unite(pcpair);
    }
}

void PolygonClipGraphWidget::onPointSelected(const QPoint &p)
{
    foreach (auto point, pp)
        updateDefaultPoints(qMakePair(point, Qt::yellow), false, true);
    pp = {};
    pv.append(p);
    foreach (auto point, pv)
        updateDefaultPoints(qMakePair(point, Qt::yellow));
}

void PolygonClipGraphWidget::onResetClicked()
{
    pv = {};
    pp = {};
    PolygonGraphWidget::onResetClicked();
}

void PolygonClipGraphWidget::performOperation()
{
    bool fl = true;
    QList<QPoint> vpv, vpp;
    for (auto i = 0; i < pv.count(); i++)
    {
        auto t = pv.at(i), t2 = pv.at((i + 1) % pv.count());
        y.setCoordinates(t.x(), t.y(), t2.x(), t2.y());
        const QVector<QPoint> p = y.drawLine();
        QVector<QPoint> tp;
        int ct = 0;
        foreach (auto point, p)
        {
            if (point.x() <= mx && point.y() <= my && point.x() >= 0 && point.y() >= 0)
            {
                ct++;
                tp.append(point);
            }
        }
        if (ct > 0)
        {
            vpv.append(tp.first());
            vpv.append(tp.last());
        }
    }
    for (auto i = 0; i < vpv.count(); i++)
    {
        auto t = vpv.at(i), t2 = vpv.at((i + 1) % vpv.count());
        x.setCoordinates(t.x(), t.y(), t2.x(), t2.y());
        const QVector<QPoint> p = x.drawLine();
        vpp.append(p);
    }
    foreach (auto point, vpp)
        editPixMap(point, qMakePair(true, false));

    qDebug() << vpv;
    if (fl)
        editPixMap(QPoint(0, 0), qMakePair(true, false));
}
