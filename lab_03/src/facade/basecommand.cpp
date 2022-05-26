#include "../facade/basecommand.h"
void DrawScene::execute()
{
    auto manager_scene = ManagerSolution::get_scene_manager();
    shared_ptr<Camera> camera = std::dynamic_pointer_cast<Camera>(manager_scene->get_camera());
    auto manager_draw = ManagerSolution::get_draw_manager();
    manager_draw->draw(drawer, camera);
}

void SetCamera::execute()
{
    auto manager_scene = ManagerSolution::get_scene_manager();
    manager_scene->set_camera(camera);
}


void LoadScene::execute()
{
    auto manager_load = ManagerSolution::get_load_manager();
    shared_ptr<Scene> scene = manager_load->load_scene(file_name);
    auto manager_scene = ManagerSolution::get_scene_manager();
    manager_scene->set_scene(scene);
}


void LoadCamera::execute()
{
    auto manager_load = ManagerSolution::get_load_manager();
    shared_ptr<Object> camera = manager_load->load_camera(file_name);
    auto manager_scene = ManagerSolution::get_scene_manager();
    manager_scene->get_scene()->add_object(camera);
}


void LoadFigure::execute()
{
    auto manager_load = ManagerSolution::get_load_manager();
    shared_ptr<Object> figure = manager_load->load_figure(file_name);
    auto manager_scene = ManagerSolution::get_scene_manager();
    manager_scene->get_scene()->add_object(figure);
}

void AddObject::execute()
{
    auto manager_scene = ManagerSolution::get_scene_manager();
    manager_scene->get_scene()->add_object(object);
}

void RemoveObject::execute()
{
    auto manager_scene = ManagerSolution::get_scene_manager();
    manager_scene->get_scene()->remove_object(index);
}

void TransferObject::execute()
{
    ScaleCoef scale(1,1,1);
    Angle rotate(0, 0, 0);

    auto manager_scene = ManagerSolution::get_scene_manager();
    shared_ptr<Object> object = *(manager_scene->get_scene()->get_objects()->begin() + index);
    object->conversion(transfer, scale, rotate);
}

void ScaleObject::execute()
{
    Point transfer(0,0,0);
    Angle rotate(0, 0, 0);

    auto manager_scene = ManagerSolution::get_scene_manager();
    shared_ptr<Object> object = *(manager_scene->get_scene()->get_objects()->begin() + index);
    object->conversion(transfer, scale, rotate);
}

void RotateObject::execute()
{
    ScaleCoef scale(1,1,1);
    Point transfer(0, 0, 0);

    auto manager_scene = ManagerSolution::get_scene_manager();
    shared_ptr<Object> object = *(manager_scene->get_scene()->get_objects()->begin() + index);
    object->conversion(transfer, scale, rotate);
}

