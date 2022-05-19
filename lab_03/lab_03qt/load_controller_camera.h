#ifndef LOAD_CONTROLLER_CAMERA_H
#define LOAD_CONTROLLER_CAMERA_H

#include "load_controller_base.h"
#include "builder_camera_base.h"
#include "camera_source_loader_base.h"

class CameraLoadController : public BaseLoadController
{
public:
    CameraLoadController(std::shared_ptr<BaseCameraBuilder> bld, std::shared_ptr<BaseCameraSourceLoader> source_loader);
    std::shared_ptr<SceneObject> load(std::string camera_name, std::string source_name) override;

private:
    std::shared_ptr<BaseCameraBuilder> builder_;
    std::shared_ptr<BaseCameraSourceLoader> source_loader_;
};

#endif // LOAD_CONTROLLER_CAMERA_H
