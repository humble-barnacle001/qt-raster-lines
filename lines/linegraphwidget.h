#ifndef LINEGRAPHWIDGET_H
#define LINEGRAPHWIDGET_H

#include "graphwidget.h"

class LineGraphWidget : public GraphWidget
{
public:
    LineGraphWidget(QWidget *parent);

protected:
    qint32 x1, y1, x2, y2;
    virtual void drawLine(QPainter &painter) = 0;

private:
    void drawShape(QPainter &painter) override;

public slots:
    void onDataPassed(int x1, int y1, int x2, int y2);
};

#endif // LINEGRAPHWIDGET_H
