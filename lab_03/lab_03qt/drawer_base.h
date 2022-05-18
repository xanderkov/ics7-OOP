#ifndef DRAWER_BASE_H
#define DRAWER_BASE_H

#include "canvas_base.h"
#include "point.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point<double> &p1, const Point<double> &p2) = 0;
    virtual void setCanvas(std::shared_ptr<BaseCanvas> canvas) = 0;

    std::shared_ptr<BaseCanvas> canvas;
};

#endif // DRAWER_BASE_H
