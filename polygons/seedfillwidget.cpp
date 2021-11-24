#include "seedfillwidget.h"

#include <chrono>

SeedFillWidget::SeedFillWidget() : isSeed(false)
{
}

void SeedFillWidget::onPointSelected(const QPoint &p)
{
    if (isSeed)
    {
        seed = p;
        // editPixMap(p, qMakePair(true, false));
        updateDefaultPoints(qMakePair(p, getFillColor()));
        isSeed = false;
        emit set_fillButton_status(true);
    }
    else
        PolygonGraphWidget::onPointSelected(p);
}

void SeedFillWidget::selectSeed()
{
    isSeed = true;
}

void SeedFillWidget::drawPolygon(bool)
{
    PolygonGraphWidget::drawPolygon();
    emit set_fillButton_status(false);
}

void SeedFillWidget::addCustomPair(const GraphWidget::CustomPair &pair)
{
    list.append(pair);
}

const GraphWidget::CustomPairList SeedFillWidget::drawShape()
{
    quint64 t0, t1;
    list = {};
    t0 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    this->seedFill(seed);

    t1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    emit send_time(this->objectName(), t1 - t0);

    return list;
}
