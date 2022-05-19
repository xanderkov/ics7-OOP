#include "canvas_qt.h"

QtCanvas::QtCanvas(std::shared_ptr<QGraphicsScene> canvas_) : BaseCanvas()
{
    graphics_scene_ = canvas_;
}

void QtCanvas::DrawLine(const Point<double> &p1, const Point<double> &p2)
{
    graphics_scene_->addLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}
