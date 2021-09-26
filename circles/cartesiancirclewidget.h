#ifndef CARTESIANCIRCLEWIDGET_H
#define CARTESIANCIRCLEWIDGET_H

#include "circlegraphwidget.h"

class CartesianCircleWidget : public CircleGraphWidget
{
public:
    CartesianCircleWidget();

private:
    const QList<QPoint> drawCircle() override;
};

#endif // CARTESIANCIRCLEWIDGET_H
