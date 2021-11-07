#ifndef SEEDFILLWIDGET_H
#define SEEDFILLWIDGET_H

#include "polygongraphwidget.h"

class SeedFillWidget : public PolygonGraphWidget
{
public:
    SeedFillWidget();

protected:
    bool isSeed;
    QPoint seed;
    virtual void seedFill(const QPoint &p) = 0;
    void addCustomPair(const GraphWidget::CustomPair &pair);

private:
    GraphWidget::CustomPairList list;
    const GraphWidget::CustomPairList drawShape() override;
    void selectSeed() override;
    void drawPolygon() override;
    void onPointSelected(const QPoint &p) override;
    void performOperation() override {}
};

#endif // SEEDFILLWIDGET_H
