#ifndef SCANLINEFILLWIDGET_H
#define SCANLINEFILLWIDGET_H

#include "polygongraphwidget.h"

class ScanLineFillWidget : public PolygonGraphWidget
{
public:
    ScanLineFillWidget();

private:
    void performOperation() override;
    void colorBetween(qsizetype y, qsizetype x1, qsizetype x2);
};

#endif // SCANLINEFILLWIDGET_H
