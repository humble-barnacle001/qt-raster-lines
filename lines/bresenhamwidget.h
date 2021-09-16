#ifndef BRESENHAMWIDGET_H
#define BRESENHAMWIDGET_H

#include "linegraphwidget.h"

class BresenhamWidget : public LineGraphWidget
{
public:
    BresenhamWidget(QWidget *parent):LineGraphWidget(parent){}

private:
    void drawLine(QPainter &qp) override;
};

#endif // BRESENHAMWIDGET_H
