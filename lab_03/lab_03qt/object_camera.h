#ifndef OBJECT_CAMERA_H
#define OBJECT_CAMERA_H

#include "matrix.h"
#include "visitor.h"
#include "object_invisible.h"
#include "point.h"

class Camera : public InvisibleObject
{
public:
    Camera(std::string name);

    void Transform(const std::shared_ptr<Matrix<double>> mtr) override;
    void Accept(std::shared_ptr<Visitor> visitor) override; // для visitor

    friend class DrawManager;
    friend class CameraBuilder;

private:
    Point<double> position;
    double x_angle;
    double y_angle;
    double z_angle;
};

#endif // OBJECT_CAMERA_H
