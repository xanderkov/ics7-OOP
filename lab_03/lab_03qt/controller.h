#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "drawer_base.h"
#include "load_controller_base.h"
#include "manager_draw.h"
#include "manager_load.h"
#include "manager_scene.h"
#include "manager_transform.h"
#include "scene.h"

class Controller
{
public:
    Controller(Controller &) = delete;
    Controller(const Controller &) = delete;
    ~Controller() = default;

    static std::shared_ptr<Controller> GetInstance();

    SceneManager scene_manager;
    TransformManager transform_manager;
    std::shared_ptr<DrawManager> draw_manager;
    std::shared_ptr<LoadManager> load_manager;

private:
    Controller();
};

#endif // CONTROLLER_H
