#include "../../../managers/manager_creator.hpp"
#include "../../../objects/model/wireframe_model/model_details/point/point.hpp"
#include "../../../objects/camera/camera.hpp"
#include "../../../facade/facade.hpp"
#include "add_camera.hpp"

AddCamera::AddCamera(double x_pos, double y_pos, double z_pos) {
    this->camera = std::make_shared<Camera>(Point(x_pos, y_pos, z_pos));
}

AddCamera::AddCamera(std::shared_ptr<Object> camera) : camera(camera) {}

void AddCamera::init(Facade &facade) {
    this->manager = facade.getSceneManager();
    this->method = &SceneManager::addObject;
}

void AddCamera::execute() {
    ((*manager).*method)(camera);
}

