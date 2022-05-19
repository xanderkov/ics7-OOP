#ifndef MANAGER_SCENE_H
#define MANAGER_SCENE_H

#include "manager_base.h"
#include "scene.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();

    std::shared_ptr<Scene> GetScene();
    void SetCurrentCamera(std::string name);
    std::shared_ptr<Camera> GetCurrentCamera();

private:
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> _current_camera;
};

#endif // MANAGER_SCENE_H
