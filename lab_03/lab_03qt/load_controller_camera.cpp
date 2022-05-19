#include "load_controller_camera.h"
#include "director_camera.h"
#include <memory.h>

CameraLoadController::CameraLoadController(std::shared_ptr<BaseCameraBuilder> bld, std::shared_ptr<BaseCameraSourceLoader> source_loader)
{
    builder_ = bld;
    source_loader_ = source_loader;
}

std::shared_ptr<SceneObject> CameraLoadController::load(std::string camera_name, std::string source_name)
{
    source_loader_->open(source_name);
    builder_->reset(camera_name);

    Point<double> position = this->source_loader_->ReadPosition();
    Point<double> angles = this->source_loader_->ReadAngles();
    source_loader_->close();

    CameraDirector director;
    director.SetBuilder(builder_);

    return director.Build(position, angles);
}
