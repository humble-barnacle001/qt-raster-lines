#ifndef SCALINGGRAPHWIDGET_H
#define SCALINGGRAPHWIDGET_H

#include "polygongraphwidget.h"

class ScalingGraphWidget : public PolygonGraphWidget
{
public:
    ScalingGraphWidget(QWidget *parent);

private:
    QPointF p;
    void performOperation() override;

public slots:
    void scaleXYChanged(const QPointF &p);
};

#endif // SCALINGGRAPHWIDGET_H
