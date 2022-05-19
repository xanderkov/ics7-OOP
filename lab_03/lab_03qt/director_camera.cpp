#include "director_camera.h"
#include <memory>

void CameraDirector::SetBuilder(std::shared_ptr<BaseCameraBuilder> builder)
{
    builder_ = std::move(builder);
}

std::shared_ptr<Camera> CameraDirector::Build(const Point<double> position, const Point<double> angles)
{
    builder_->BuildPosition(position);
    builder_->BuildAngles(angles);

    return builder_->GetCamera();
}
