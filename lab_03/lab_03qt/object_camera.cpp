#include "object_camera.h"

Camera::Camera(std::string name)
{
    std::cout << "her0" << std::endl;
    this->_name = name;
}

void Camera::Transform(const std::shared_ptr<Matrix<double>> mtr)
{
    position.Transform(mtr);
}

void Camera::Accept(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(*this);
}
