#include "../../../managers/manager_creator.hpp"
#include "../../../managers/scene/scene_manager.hpp"
#include "../../../facade/facade.hpp"
#include "remove_camera.hpp"

RemoveCamera::RemoveCamera(std::size_t camera_id) : camera_id(camera_id) {}

void RemoveCamera::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::removeObject;
}

void RemoveCamera::execute() {
    ((*manager).*method)(camera_id);
}

