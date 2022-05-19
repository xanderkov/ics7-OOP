#ifndef DIRECTOR_CAMERA_H
#define DIRECTOR_CAMERA_H

#include <memory>

#include "builder_camera_base.h"
#include "camera_source_loader_base.h"
#include "object_camera.h"

class CameraDirector
{
public:
    std::shared_ptr<Camera> Build(const Point<double> position, const Point<double> angles);
    void SetBuilder(std::shared_ptr<BaseCameraBuilder> builder);

private:
    std::shared_ptr<BaseCameraBuilder> builder_;
};


#endif // DIRECTOR_CAMERA_H
