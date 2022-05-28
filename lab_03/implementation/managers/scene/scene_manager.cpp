#include "../../exceptions/load_exceptions.hpp"
#include "../../objects/camera/camera.hpp"
#include "scene_manager.hpp"

SceneManager::SceneManager() : scene(std::make_shared<Scene>()) {}

std::shared_ptr<Camera> SceneManager::getMainCamera() const {
    auto camera_ptr = this->main_camera.lock();

    if (camera_ptr == nullptr) throw NoCameraError(__FILE__, __LINE__, "main camera doesn't installed");

    return camera_ptr;
}

std::shared_ptr<Scene> SceneManager::getScene() const {
    return this->scene;
}

void SceneManager::setScene(std::shared_ptr<Scene> new_scene) {
    this->scene = std::move(new_scene);
}

void SceneManager::setMainCamera(size_t camera_id) {

    auto it = getScene()->begin();
    std::advance(it, camera_id);
    this->main_camera = std::dynamic_pointer_cast<Camera>(*it);
}


std::shared_ptr<Object> SceneManager::getObjectById(size_t id) {
    auto obj_iter = this->scene->begin();
    std::advance(obj_iter, id);
    std::shared_ptr<Object> obj = *obj_iter;

    return obj;
}

void SceneManager::addObject(const std::shared_ptr<Object> &object) {
    this->scene->addObject(object);
}

void SceneManager::removeObject(size_t id) {
    auto it = this->scene->begin();
    std::advance(it, id);
    this->scene->removeObject(it);
}

[[nodiscard]] size_t SceneManager::getCamerasCount() const {
    return this->scene->getCamerasCount();
}

[[nodiscard]] size_t SceneManager::getModelsCount() const {
    return this->scene->getModelsCount();
}