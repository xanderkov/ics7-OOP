#ifndef MANAGER_DRAW_H
#define MANAGER_DRAW_H

#include "visitor.h"
#include "manager_base.h"
#include "matrix.h"
#include "drawer_base.h"
#include "scene.h"

class DrawManager : public BaseManager, public Visitor
{
public:
    void SetDrawer(std::shared_ptr<BaseDrawer> drawer);
    void SetCamera(std::shared_ptr<Camera> camera);
    void Visit(Model &model);
    void Visit(Camera &camera);
    void Visit(CompositeObject &comp);

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
    void ProjectPoint(Point<double> &point);
};

#endif // MANAGER_DRAW_H
