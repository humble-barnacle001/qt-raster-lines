#ifndef REFLECTIONGRAPHWIDGET_H
#define REFLECTIONGRAPHWIDGET_H

#include "polygongraphwidget.h"

class ReflectionGraphWidget : public PolygonGraphWidget
{
public:
    ReflectionGraphWidget(QWidget *parent);

private:
    int line;
    QPoint a, b;
    void performOperation() override;

    void onPointSelected(const QPoint &p) override;
    void drawPolygon(bool) override;

    void onResetClicked() override;

public slots:
    void lineSelected();
};

#endif // REFLECTIONGRAPHWIDGET_H
