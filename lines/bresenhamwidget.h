#ifndef BRESENHAMWIDGET_H
#define BRESENHAMWIDGET_H

#include "linegraphwidget.h"

class BresenhamWidget : public LineGraphWidget
{
public:
    BresenhamWidget(QWidget *parent) : LineGraphWidget(parent) {}
    const QList<QPoint> drawLine() override;
};

#endif // BRESENHAMWIDGET_H
