#ifndef BOUNDARYFILLWIDGET_H
#define BOUNDARYFILLWIDGET_H

#include "seedfillwidget.h"

class BoundaryFillWidget : public SeedFillWidget
{
public:
    BoundaryFillWidget();

private:
    void seedFill(const QPoint &p) override;
};

#endif // BOUNDARYFILLWIDGET_H
