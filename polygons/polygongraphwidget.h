#ifndef POLYGONGRAPHWIDGET_H
#define POLYGONGRAPHWIDGET_H

#include <QSet>

#include "util/graphwidget.h"
#include "lines/bresenhamwidget.h"

class PolygonGraphWidget : public GraphWidget
{
public:
    PolygonGraphWidget(QWidget *parent = nullptr);
    void polygonOperation();
    const GraphWidget::CustomPairList getColoredPixels();

private:
    BresenhamWidget x;
    QList<QPoint> selected;
    QSet<QPoint> polygon;
    qsizetype max;
    bool animatePolygon;
    Qt::GlobalColor polygonColor;
    Qt::GlobalColor fillColor;
    /**
     * @brief 
     * 00 - None
     * 01 - Polygon
     * 10 - Color
     * 11 - Invalid
     * 
     */
    QVector<QVector<QPair<bool, bool>>> pixelMap;
    void constructPixMap(int w = 5);

protected:
    const GraphWidget::CustomPairList drawShape() override;
    Qt::GlobalColor getFillColor();
    const QVector<QPair<bool, bool>> *getPixMap();
    /**
     * @brief Edit the pixelMap
     * 
     * @param p Point on x-y plane in graph
     * @param pair Valid pair(00, 01, 10)
     */
    void editPixMap(const QPoint &p, const QPair<bool, bool> &pair);
    const QPoint pixMapToPoint(int row, int column);
    const QPair<bool, bool> &getPixMapAt(const QPoint &p);
    const QPair<bool, bool> &getPixMapAt(int row, int column);
    qsizetype getPixMapSize();
    virtual void performOperation() = 0;

public slots:
    virtual void onPointSelected(const QPoint &p);
    virtual void drawPolygon();
    void onResetClicked();
    void onGridWidthChanged(int w);
    virtual void selectSeed() {}
};

#endif // POLYGONGRAPHWIDGET_H
