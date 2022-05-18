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
    controller->load_manager_->set_loader(load_controller);
    std::shared_ptr<SceneObject> camera = controller->load_manager_->load(camera_name, file_name);
    controller->scene_manager_.GetScene()->Add(std::shared_ptr<SceneObject>(camera));
}

AddModelCommand::AddModelCommand(std::string model_name, std::string file_name, std::shared_ptr<BaseModelSourceLoader> loader) :
    model_name(model_name), file_name(file_name), source_loader(loader) {}

void AddModelCommand::Run(std::shared_ptr<Controller> controller)
{
    std::shared_ptr<BaseModelBuilder> bld(std::make_shared<ModelBuilder>());
    auto load_controller = std::make_shared<ModelLoadController>(bld, source_loader);
    controller->load_manager_->set_loader(load_controller);
    std::shared_ptr<SceneObject> model = controller->load_manager_->load(model_name, file_name);
    controller->scene_manager_.GetScene()->Add(std::shared_ptr<SceneObject>(model));
}

RemoveObjectCommand::RemoveObjectCommand(std::string object_name) : object_name_(object_name) {}

void RemoveObjectCommand::Run(std::shared_ptr<Controller> controller)
{
    auto scene = controller->scene_manager_.GetScene();
    IteratorObject iter = scene->GetObject()->begin();
    IteratorObject iter_end = scene->GetObject()->end();
    bool flag = true;

    while (iter != iter_end && flag)
    {
        auto tmp = *iter;
        if (tmp->GetName() == object_name_)
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


DrawCommand::DrawCommand(std::shared_ptr<BaseDrawer> drawer) : drawer_(drawer) {}

void DrawCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->draw_manager_->SetDrawer(drawer_);
    controller->draw_manager_->SetCamera(controller->scene_manager_.GetCurrentCamera());

    controller->scene_manager_.GetScene()->GetObject()->Accept(controller->draw_manager_);
}

SetCameraCommand::SetCameraCommand(std::string name) : name_(name) {}

void SetCameraCommand::Run(std::shared_ptr<Controller> controller)
{
    controller->scene_manager_.SetCurrentCamera(name_);
}

TransformObjectCommand::TransformObjectCommand(std::string object_name, Point<double> &move, Point<double> &scale, Point<double> &rotate) : object_name_(object_name), move_(move), scale_(scale), rotate_(rotate) {}

void TransformObjectCommand::Run(std::shared_ptr<Controller> controller)
{
    auto obj = controller->scene_manager_.GetScene()->GetObject(object_name_);

    controller->transform_manager_.MoveObject(obj, move_.getX(), move_.getY(), move_.getZ());
    controller->transform_manager_.RotateX(obj, rotate_.getX());
    controller->transform_manager_.RotateY(obj, rotate_.getY());
    controller->transform_manager_.RotateZ(obj, rotate_.getZ());
    controller->transform_manager_.ScaleObject(obj, scale_.getX(), scale_.getY(), scale_.getZ());
}
