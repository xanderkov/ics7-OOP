#include "../../../managers/manager_creator.hpp"
#include "../../../facade/facade.hpp"
#include <utility>
#include "get_main_camera.hpp"

GetMainCamera::GetMainCamera(std::shared_ptr<Camera> &camera) : camera(camera) {}

void GetMainCamera::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::getMainCamera;
}

void GetMainCamera::execute() {
    this->camera = ((*manager).*method)();
}