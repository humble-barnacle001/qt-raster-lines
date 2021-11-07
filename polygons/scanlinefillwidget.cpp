#include "scanlinefillwidget.h"

#include <QDebug>

ScanLineFillWidget::ScanLineFillWidget()
{
}

void ScanLineFillWidget::performOperation()
{
    for (qsizetype y = 0; y < getPixMapSize(); y++)
    {
        qsizetype first = -1;
        for (qsizetype x = 0; x < getPixMapSize(); x++)
        {
            if (getPixMapAt(y, x).second)
            {
                if (first != -1)
                {
                    colorBetween(y, first, x);
                    first = -1;
                    // first = first - x == 1 ? -1 : x;
                    // x--;
                }
                else
                    first = x;
            }
        }
    }
}

void ScanLineFillWidget::colorBetween(qsizetype y, qsizetype x1, qsizetype x2)
{
    while (++x1 < x2)
        editPixMap(pixMapToPoint(y, x1), qMakePair(true, false));
}
