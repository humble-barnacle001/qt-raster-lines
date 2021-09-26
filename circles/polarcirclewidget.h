#ifndef POLARCIRCLEWIDGET_H
#define POLARCIRCLEWIDGET_H

#include "circlegraphwidget.h"

class PolarCircleWidget : public CircleGraphWidget
{
public:
    PolarCircleWidget();

private:
    const QList<QPoint> drawCircle() override;
};

#endif // POLARCIRCLEWIDGET_H
