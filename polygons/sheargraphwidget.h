#ifndef SHEARGRAPHWIDGET_H
#define SHEARGRAPHWIDGET_H

#include "polygongraphwidget.h"

class ShearGraphWidget : public PolygonGraphWidget
{
public:
    ShearGraphWidget(QWidget *parent);

private:
    QPointF p;
    void performOperation() override;

public slots:
    void scaleXYChanged(const QPointF &p);
};

#endif // SHEARGRAPHWIDGET_H
