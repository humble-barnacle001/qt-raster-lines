#ifndef TRANSLATIONGRAPHWIDGET_H
#define TRANSLATIONGRAPHWIDGET_H

#include "polygongraphwidget.h"

class TranslationGraphWidget : public PolygonGraphWidget
{
public:
    TranslationGraphWidget(QWidget *parent);

private:
    QPoint p;
    void performOperation() override;

public slots:
    void translateXYChanged(const QPoint &p);
};

#endif // TRANSLATIONGRAPHWIDGET_H
