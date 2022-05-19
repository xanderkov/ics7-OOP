#ifndef MANAGER_TRANSFORM_H
#define MANAGER_TRANSFORM_H

#include <cmath>
#include <memory>

#include "manager_base.h"
#include "matrix_transform.h"
#include "object_scene.h"
#include "scene.h"

class TransformManager : public BaseManager
{
public:
    void MoveObject(std::shared_ptr<SceneObject> obj, int dx, int dy, int dz);
    void ScaleObject(std::shared_ptr<SceneObject> obj, double x, double y, double z);
    void RotateX(std::shared_ptr<SceneObject> obj, double angle);
    void RotateY(std::shared_ptr<SceneObject> obj, double angle);
    void RotateZ(std::shared_ptr<SceneObject> obj, double angle);

private:
    double DegToRad(double angle);
};

#endif // MANAGER_TRANSFORM_H
