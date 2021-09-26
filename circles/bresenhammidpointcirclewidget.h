#ifndef BRESENHAMMIDPOINTCIRCLEWIDGET_H
#define BRESENHAMMIDPOINTCIRCLEWIDGET_H

#include "circlegraphwidget.h"

class BresenhamMidpointCircleWidget : public CircleGraphWidget
{
public:
    BresenhamMidpointCircleWidget();

private:
    const QList<QPoint> drawCircle() override;
};

#endif // BRESENHAMMIDPOINTCIRCLEWIDGET_H
