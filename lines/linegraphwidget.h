#ifndef LINEGRAPHWIDGET_H
#define LINEGRAPHWIDGET_H

#include "util/graphwidget.h"

class LineGraphWidget : public GraphWidget
{
public:
    LineGraphWidget(QWidget *parent);
    void setCoordinates(int x1, int y1, int x2, int y2);
    virtual const QList<QPoint> drawLine() = 0;

private:
    const GraphWidget::CustomPairList drawShape() override;

protected:
    qint32 x1, y1, x2, y2;

public slots:
    void onDataPassed(int x1, int y1, int x2, int y2);
};

#endif // LINEGRAPHWIDGET_H
