#ifndef ROTATIONGRAPHWIDGET_H
#define ROTATIONGRAPHWIDGET_H

#include "polygongraphwidget.h"

class RotationGraphWidget : public PolygonGraphWidget
{
public:
    RotationGraphWidget(QWidget *parent);

private:
    int deg;
    void performOperation() override;

public slots:
    void angleChanged(int deg);
};

#endif // ROTATIONGRAPHWIDGET_H
