#include "../../../managers/manager_creator.hpp"
#include "../../../managers/scene/scene_manager.hpp"
#include "../../../facade/facade.hpp"
#include "add_model.hpp"

AddModel::AddModel(std::shared_ptr<Object> model) : model(model) {}

void AddModel::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::addObject;
}

void AddModel::execute() {
    ((*manager).*method)(model);
}

 