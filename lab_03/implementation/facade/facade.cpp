#include "facade.hpp"
#include "../managers/manager_creator.hpp"

Facade::Facade() {
    this->loadManager = ManagerCreator<LoadManager>().getManager();
    this->drawManager = ManagerCreator<DrawManager>().getManager();
    this->transformManager = ManagerCreator<TransformManager>().getManager();
    this->sceneManager = ManagerCreator<SceneManager>().getManager();
}

std::shared_ptr<LoadManager> Facade::getLoadManager() {
    return loadManager;
}

std::shared_ptr<DrawManager> Facade::getDrawManager() {
    return drawManager;
}

std::shared_ptr<SceneManager> Facade::getSceneManager() {
    return sceneManager;
}

std::shared_ptr<TransformManager> Facade::getTransformManager() {
    return transformManager;
}

void Facade::execute(const std::shared_ptr<Command> &command) {
    command->init(*this);
    command->execute();
}
