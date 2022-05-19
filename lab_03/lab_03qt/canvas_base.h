#ifndef CANVAS_BASE_H
#define CANVAS_BASE_H

#include "point.h"

class BaseCanvas
{
public:
    virtual void DrawLine(const Point<double> &p1, const Point<double> &p2) = 0;
};

#endif // CANVAS_BASE_H
