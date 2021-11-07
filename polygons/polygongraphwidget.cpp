#include "polygongraphwidget.h"

#include <chrono>

#include <QDebug>

PolygonGraphWidget::PolygonGraphWidget(QWidget *parent)
    : GraphWidget(parent, 479),
      x(nullptr), max(std::ceil(479 / 2 / 5) - 1),
      animatePolygon(true), polygonColor(Qt::cyan), fillColor(Qt::magenta)
{
    connect(this, &GraphWidget::mouse_dbl_clicked, this, &PolygonGraphWidget::onPointSelected);

    constructPixMap();
}

void PolygonGraphWidget::onPointSelected(const QPoint &p)
{
    GraphWidget::onResetClicked();
    editPixMap(p, qMakePair(false, true));
    if (!selected.contains(p))
        selected.append(p);
    foreach (auto point, selected)
        updateDefaultPoints(qMakePair(point, polygonColor));
}

void PolygonGraphWidget::drawPolygon()
{
    if (selected.size() < 3)
        return;
    constructPixMap(GraphWidget::getGridWidth());
    emit set_draw_status(this->objectName(), false);
    GraphWidget::onResetClicked();
    polygon = {};
    for (auto i = 0; i < selected.count(); i++)
    {
        auto t = selected.at(i), t2 = selected.at((i + 1) % selected.count());
        x.setCoordinates(t.x(), t.y(), t2.x(), t2.y());
        const QVector<QPoint> p = x.drawLine();
        QSet<QPoint> pcpair;
        for (qsizetype i = 0; i < p.size(); i++)
        {
            auto point = p.at(i);
            pcpair.insert(point);
            editPixMap(point, qMakePair(false, true));
            GraphWidget::updateDefaultPoints(
                qMakePair(point, polygonColor), animatePolygon ? true : i == p.size() - 1);
        }
        polygon.unite(pcpair);
    }
    GraphWidget::updateDefaultPoints(qMakePair(selected.first(), Qt::darkGreen));
    GraphWidget::updateDefaultPoints(qMakePair(selected.last(), Qt::darkGreen));
    emit set_draw_status(this->objectName(), true, false);
}

void PolygonGraphWidget::onResetClicked()
{
    selected = {};
    polygon = {};
    constructPixMap(GraphWidget::getGridWidth());
    GraphWidget::onResetClicked();
}

void PolygonGraphWidget::onGridWidthChanged(int w)
{
    constructPixMap(w);
    GraphWidget::onGridWidthChanged(w);
}

void PolygonGraphWidget::polygonOperation()
{
    this->m_shape = true;
    this->animateDraw();
}

const GraphWidget::CustomPairList PolygonGraphWidget::drawShape()
{
    quint64 t0, t1;
    t0 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    this->performOperation();

    t1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    emit send_time(this->objectName(), t1 - t0);

    return getColoredPixels();
}

Qt::GlobalColor PolygonGraphWidget::getFillColor()
{
    return fillColor;
}

void PolygonGraphWidget::constructPixMap(int w)
{
    pixelMap = {};
    max = std::ceil(479 / 2 / w) - 1;
    for (qsizetype i = 0; i < max * 2; i++)
    {
        QVector<QPair<bool, bool>> rowMap;
        for (qsizetype j = 0; j < max * 2; j++)
        {
            rowMap.append(qMakePair(false, false));
        }
        pixelMap.append(rowMap);
    }
}

const QVector<QPair<bool, bool>> *PolygonGraphWidget::getPixMap()
{
    return pixelMap.data();
}

void PolygonGraphWidget::editPixMap(const QPoint &p, const QPair<bool, bool> &pair)
{
    ((pixelMap.data())[max - p.y() - 1].data())[p.x() + max] = pair;
}

const QPoint PolygonGraphWidget::pixMapToPoint(int row, int column)
{
    return QPoint(column - max, max - row - 1);
}

const QPair<bool, bool> &PolygonGraphWidget::getPixMapAt(const QPoint &p)
{
    return ((pixelMap.data())[max - p.y() - 1].data())[p.x() + max];
}

const QPair<bool, bool> &PolygonGraphWidget::getPixMapAt(int row, int column)
{
    return ((pixelMap.data())[row].data())[column];
}

qsizetype PolygonGraphWidget::getPixMapSize()
{
    return pixelMap.size();
}

const GraphWidget::CustomPairList PolygonGraphWidget::getColoredPixels()
{
    GraphWidget::CustomPairList temp;
    for (qsizetype y = 0; y < getPixMapSize(); y++)
    {
        for (qsizetype x = 0; x < getPixMapSize(); x++)
        {
            auto t = getPixMapAt(y, x);
            if (t.first && !t.second)
                temp.append(qMakePair(pixMapToPoint(y, x), fillColor));
        }
    }
    return temp;
}

