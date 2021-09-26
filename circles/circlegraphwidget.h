#ifndef CIRCLEGRAPHWIDGET_H
#define CIRCLEGRAPHWIDGET_H

#include "util/graphwidget.h"

class CircleGraphWidget : public GraphWidget
{

public:
    CircleGraphWidget(QWidget *parent = nullptr, qsizetype dim = 479, quint32 timer = 100);

protected:
    qint32 cx, cy, r;
    virtual const QList<QPoint> drawCircle() = 0;
    const QList<QPoint> eightWaySymmetric(qint32 x, qint32 y);

private:
    const QList<QPoint> drawShape() override;

public slots:
    void onDataPassed(qint32 cx, qint32 cy, qint32 r);
};

#endif // CIRCLEGRAPHWIDGET_H
