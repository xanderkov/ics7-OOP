#include <ctime>

#include "error_drawer.h"
#include "matrix_transform.h"
#include "manager_draw.h"

void DrawManager::ProjectPoint(Point<double> &point)
{
    Point<double> cam_pos(_camera->position);

    std::shared_ptr<Matrix<double>> proj_matrix(std::make_shared<MoveMatrix>(-cam_pos.getX(), -cam_pos.getY(), 0));
    point.Transform(proj_matrix);

    proj_matrix.reset(new RotateOxMatrix(-_camera->x_angle));
    point.Transform(proj_matrix);

    proj_matrix.reset(new RotateOyMatrix(-_camera->y_angle));
    point.Transform(proj_matrix);

    proj_matrix.reset(new RotateOzMatrix(-_camera->z_angle));
    point.Transform(proj_matrix);

    double eps = 1e-10;
    double denom = point.getZ() + cam_pos.getZ();

    if (denom < eps && denom > -eps)
        denom = eps;

    double distCoef = cam_pos.getZ() / denom;

    point.setX(point.getX() * distCoef);
    point.setY(point.getY() * distCoef);
}

void DrawManager::SetDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}

void DrawManager::SetCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}

void DrawManager::Visit(Model &model)
{
    time_t t_time = time(NULL);

    if (!_drawer)
    {
        throw DrawerError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    if (!_camera)
    {
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    auto carcass = model._carcass;
    auto edges = carcass->GetEdges();

    for (auto &edge : edges)
    {
        ProjectPoint(edge.get_first());
        ProjectPoint(edge.get_second());
        _drawer->drawLine(edge.get_first() + carcass->GetCentre(), edge.get_second() + carcass->GetCentre());
    }
}

void DrawManager::Visit(Camera &camera) {}

void DrawManager::Visit(CompositeObject &comp) {}
