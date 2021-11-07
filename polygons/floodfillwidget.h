#ifndef FLOODFILLWIDGET_H
#define FLOODFILLWIDGET_H

#include "seedfillwidget.h"

class FloodFillWidget : public SeedFillWidget
{
public:
    FloodFillWidget();

private:
    void seedFill(const QPoint &p) override;
};

#endif // FLOODFILLWIDGET_H
