#include "drawmanager.h"
#include "../visitor/visitor.h"
#include "../objects/edge.h"
#include "../managers/managersolution.h"
#include <vector>
#include "../objects/composite.h"
#include <stdarg.h>

#define WINDOW_CENTER_W 300
#define WINDOW_CENTER_H 300

void DrawManager::draw(const shared_ptr<BaseDrawer> &drawer, const shared_ptr<Camera> &camera)
{
    auto manager_scene = ManagerSolution::get_scene_manager();
    shared_ptr<Object> object = *(manager_scene->get_scene()->get_objects()->begin() + 0);
    Visitor visitor(camera);
    scene->accept(visitor);

    const vector<Pixel> pixels = visitor.get_pixels();
    const vector<Edge> edges = visitor.get_edges();


    for (const auto &edge : edges)
        drawer->add_line(pixels[edge.get_first()], pixels[edge.get_second()]);
}


void DrawManagerCreator::create_manager()
{
    static shared_ptr<DrawManager>_manager(new DrawManager);
    manager = _manager;
}

shared_ptr<DrawManager> DrawManagerCreator::get_manager()
{
    if (manager == nullptr)
        create_manager();

    return manager;
}