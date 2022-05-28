#include "../../../managers/manager_creator.hpp"
#include "../../../facade/facade.hpp"
#include <utility>
#include "get_object.hpp"

GetSceneObject::GetSceneObject(std::shared_ptr<Object> &object, size_t id) : object(object), id(id) {}

void GetSceneObject::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::getObjectById;
}

void GetSceneObject::execute() {
    this->object = ((*manager).*method)(id);
}