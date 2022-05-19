#include "builder_camera.h"

void CameraBuilder::BuildPosition(const Point<double> centre)
{
    camera->position = centre;
}

void CameraBuilder::BuildAngles(const Point<double> angles)
{
    camera->x_angle = angles.getX();
    camera->y_angle = angles.getY();
    camera->z_angle = angles.getZ();
}

void CameraBuilder::reset(std::string name)
{
    camera.reset();
    camera = std::shared_ptr<Camera>(std::make_shared<Camera>(name));
}

std::shared_ptr<Camera> CameraBuilder::GetCamera()
{
    return camera;
}
