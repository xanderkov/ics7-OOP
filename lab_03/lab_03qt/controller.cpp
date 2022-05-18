#include "controller.h"
#include "builder_model.h"
#include "model_source_loader_file.h"
#include "load_controller_model.h"
#include "error_scene.h"

Controller::Controller() : draw_manager(std::make_shared<DrawManager>()), load_manager(std::make_shared<LoadManager>())
{

}

std::shared_ptr<Controller> Controller::GetInstance()
{
    static std::shared_ptr<Controller> instance(new Controller());

    return instance;
}
