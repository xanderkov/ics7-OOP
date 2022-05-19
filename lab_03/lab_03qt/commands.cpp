#include "commands.h"
#include "error_scene.h"
#include "point.h"
#include "load_controller_model.h"
#include "load_controller_camera.h"
#include "builder_model.h"
#include "builder_camera.h"

AddCameraCommand::AddCameraCommand(std::string camera_name, std::string file_name, std::shared_ptr<BaseCameraSourceLoader> loader) :
    camera_name(camera_name), file_name(file_name), source_loader(loader) {}


void AddCameraCommand::Run(std::shared_ptr<Controller> controller)
{
    std::shared_ptr<BaseCameraBuilder> bld(std::make_shared<CameraBuilder>());
    auto load_controller = std::make_shared<CameraLoadController>(bld, source_loader);
    controller->load_manager->set_loader(load_controller);
    std::shared_ptr<SceneObject> camera = controller->load_manager->load(camera_name, file_name);
    controller->scene_manager.GetScene()->Add(std::shared_ptr<SceneObject>(camera));
}

AddModelCommand::AddModelCommand(std::string model_name, std::string file_name, std::shared_ptr<BaseModelSourceLoader> loader) :
    model_name(model_name), file_name(file_name), source_loader(loader) {}

void AddModelCommand::Run(std::shared_ptr<Controller> controller)
{
    std::shared_ptr<BaseModelBuilder> bld(std::make_shared<ModelBuilder>());
    auto load_controller = std::make_shared<ModelLoadController>(bld, source_loader);
    controller->load_manager->set_loader(load_controller);
    std::shared_ptr<SceneObject> model = controller->load_manager->load(model_name, file_name);
    controller->scene_manager.GetScene()->Add(std::shared_ptr<SceneObject>(model));
}

RemoveObjectCommand::RemoveObjectCommand(std::string object_name) : _object_name(object_name) {}

void RemoveObjectCommand::Run(std::shared_ptr<Controller> controller)
{
    auto scene = controller->scene_manager.GetScene();
    IteratorObject iter = scene->GetObject()->begin();
    IteratorObject iter_end = scene->GetObject()->end();
    bool flag = true;

    while (iter != iter_end && flag)
    {
        auto tmp = *iter;
        if (tmp->GetName() == _object_name)
        {
            flag = false;
        }
        if (flag)
        {
            ++iter;
        }
    }

    time_t t_time = time(NULL);

    if (iter != iter_end)
    {
        scene->Remove(iter);
    }
    else
    {
        throw ObjectError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}


DrawCommand::DrawCommand(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) {}

void DrawCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->draw_manager->SetDrawer(_drawer);
    controller->draw_manager->SetCamera(controller->scene_manager.GetCurrentCamera());

    controller->scene_manager.GetScene()->GetObject()->Accept(controller->draw_manager);
}

SetCameraCommand::SetCameraCommand(std::string name) : _name(name) {}

void SetCameraCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->scene_manager.SetCurrentCamera(_name);
}

TransformObjectCommand::TransformObjectCommand(std::string object_name, Point<double> &move, Point<double> &scale, Point<double> &rotate) : _object_name(object_name), _move(move), _scale(scale), _rotate(rotate) {}

void TransformObjectCommand::Run(std::shared_ptr<Controller> controller)
{
    auto obj = controller->scene_manager.GetScene()->GetObject(_object_name);

    controller->transform_manager.MoveObject(obj, _move.getX(), _move.getY(), _move.getZ());
    controller->transform_manager.RotateX(obj, _rotate.getX());
    controller->transform_manager.RotateY(obj, _rotate.getY());
    controller->transform_manager.RotateZ(obj, _rotate.getZ());
    controller->transform_manager.ScaleObject(obj, _scale.getX(), _scale.getY(), _scale.getZ());
}
