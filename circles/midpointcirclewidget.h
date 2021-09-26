#ifndef MIDPOINTCIRCLEWIDGET_H
#define MIDPOINTCIRCLEWIDGET_H

#include "circlegraphwidget.h"

class MidpointCircleWidget : public CircleGraphWidget
{
public:
    MidpointCircleWidget();

private:
    const QList<QPoint> drawCircle() override;
};

#endif // MIDPOINTCIRCLEWIDGET_H
