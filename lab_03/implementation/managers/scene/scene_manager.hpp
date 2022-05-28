#ifndef __LAB_03_SCENE_MANAGER_HPP__
#define __LAB_03_SCENE_MANAGER_HPP__


#include <memory>
#include "../manager.hpp"
#include "../../scene/scene.hpp"

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;


class SceneManager : public Manager {
public:
    SceneManager();
    SceneManager(const SceneManager &) = delete;
    SceneManager &operator=(const SceneManager &) = delete;
    ~SceneManager() override = default;

    [[nodiscard]] std::shared_ptr<Scene> getScene() const;
    [[nodiscard]] std::shared_ptr<Camera> getMainCamera() const;

    void setScene(std::shared_ptr<Scene> scene);
    void setMainCamera(size_t camera_id);
    std::shared_ptr<Object> getObjectById(size_t id);
    void addObject(const std::shared_ptr<Object> &object);
    void removeObject(size_t id);

    [[nodiscard]] size_t getCamerasCount() const;
    [[nodiscard]] size_t getModelsCount() const;

private:
    std::shared_ptr<Scene> scene;
    std::weak_ptr<Camera> main_camera;
};

#endif //__LAB_03_SCENE_MANAGER_HPP__
