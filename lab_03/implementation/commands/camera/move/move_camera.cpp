#include "../../../managers/manager_creator.hpp"
#include "../../../objects/model/wireframe_model/model_details/point/point.hpp"
#include "../../../facade/facade.hpp"
#include "move_camera.hpp"

MoveCamera::MoveCamera(std::shared_ptr<Object> camera, double shift_x, double shift_y) : camera(camera), shift_x(shift_x), shift_y(shift_y){}

void MoveCamera::init(Facade &facade) {
    this->manager = facade.getTransformManager();
    this->method = &TransformManager::transform;
}

void MoveCamera::execute() {
    ((*manager).*method)(camera, Point(shift_x, shift_y, 0), Point(shift_x, shift_y, 0), Point(shift_x, shift_y, 0));
}

