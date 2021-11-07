#ifndef DDAWIDGET_H
#define DDAWIDGET_H

#include "linegraphwidget.h"

class DDAWidget : public LineGraphWidget
{
public:
    DDAWidget(QWidget *parent) : LineGraphWidget(parent) {}
    const QList<QPoint> drawLine() override;
};

#endif // DDAWIDGET_H
