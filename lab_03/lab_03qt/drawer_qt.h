#ifndef DRAWER_QT_H
#define DRAWER_QT_H

#include <QGraphicsScene>
#include <memory>

#include "drawer_base.h"
#include "point.h"

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = default;

    void drawLine(const Point<double> &p1, const Point<double> &p2) override;
    void setCanvas(std::shared_ptr<BaseCanvas> canvas_) override;
};

#endif // DRAWER_QT_H
