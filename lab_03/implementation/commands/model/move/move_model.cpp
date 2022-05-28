#include "../../../managers/manager_creator.hpp"
#include "../../../objects/model/wireframe_model/model_details/point/point.hpp"
#include "../../../facade/facade.hpp"
#include "move_model.hpp"

MoveModel::MoveModel(std::shared_ptr<Object> model, double dx, double dy, double dz) 
                                            : model(model), dx(dx), dy(dy), dz(dz) {}

void MoveModel::init(Facade &facade) {
    this->manager = facade.getTransformManager();
    this->method = &TransformManager::transform;      
}

void MoveModel::execute() {
    ((*manager).*method)(model, Point(dx, dy, dz), Point(1, 1, 1), Point(0, 0, 0));
}
