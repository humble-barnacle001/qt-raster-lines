#ifndef LINECLIPGRAPHWIDGET_H
#define LINECLIPGRAPHWIDGET_H

#include "polygongraphwidget.h"

class LineClipGraphWidget : public PolygonGraphWidget
{
public:
    LineClipGraphWidget(QWidget *parent);

private:
    int line;
    int mx, my;
    QPoint a, b;
    QList<QPoint> lp;
    void performOperation() override;

    void onPointSelected(const QPoint &p) override;
    void drawPolygon(bool) override;
    void onResetClicked() override;

public slots:
    void translateXYChanged(const QPoint &p);
};

#endif // LINECLIPGRAPHWIDGET_H
