#include "../../../managers/manager_creator.hpp"
#include "../../../facade/facade.hpp"
#include "count_cameras.hpp"

CountCameras::CountCameras(std::shared_ptr<size_t> &count) : count(count) {}

void CountCameras::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::getCamerasCount;
}

void CountCameras::execute() {
    *(this->count) = ((*manager).*method)();
}

 