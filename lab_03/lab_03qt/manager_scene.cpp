#include "manager_scene.h"
#include "error_scene.h"

SceneManager::SceneManager() : scene(new Scene()) {}

std::shared_ptr<Scene> SceneManager::GetScene()
{
    return scene;
}

void SceneManager::SetCurrentCamera(std::string name)
{
    // динамическое приведение типа именно к камере
    _current_camera = std::dynamic_pointer_cast<Camera>(scene->GetObject(name));
}

std::shared_ptr<Camera> SceneManager::GetCurrentCamera()
{
    time_t t_time = time(NULL);

    if (!_current_camera)
    {
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    return _current_camera;
}
