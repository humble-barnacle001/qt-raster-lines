#include "rotationgraphwidget.h"

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

RotationGraphWidget::RotationGraphWidget(QWidget *parent)
    : PolygonGraphWidget(parent)
{
}

void RotationGraphWidget::angleChanged(int deg)
{
    this->deg = deg;
}

void RotationGraphWidget::performOperation()
{
    double rad = M_PI / 180 * deg;
    foreach (auto pp, polygon)
    {
        editPixMap(QPoint(std::round(pp.x() * std::cos(rad) - pp.y() * std::sin(rad)), std::round(pp.x() * std::sin(rad) + pp.y() * std::cos(rad))), qMakePair(true, false));
    }
}
