#ifndef POLYGONCLIPGRAPHWIDGET_H
#define POLYGONCLIPGRAPHWIDGET_H

#include "polygongraphwidget.h"

#include "lines/ddawidget.h"

class PolygonClipGraphWidget : public PolygonGraphWidget
{
public:
    PolygonClipGraphWidget(QWidget *parent);

private:
    int mx, my;
    QList<QPoint> pv;
    QSet<QPoint> pp;
    DDAWidget y;
    void performOperation() override;

    void onPointSelected(const QPoint &p) override;
    void drawPolygon(bool animate) override;
    void onResetClicked() override;

public slots:
    void translateXYChanged(const QPoint &p);
    void drawArtifact();
};

#endif // POLYGONCLIPGRAPHWIDGET_H
