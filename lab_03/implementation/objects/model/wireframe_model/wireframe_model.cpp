#include "wireframe_model.hpp"

WireframeModel::WireframeModel() : details(std::make_shared<WireframeModelDetails>()) {}

WireframeModel::WireframeModel(std::shared_ptr<WireframeModelDetails> details) : details(std::move(details)) {}

WireframeModel::WireframeModel(const WireframeModel& model) {
    this->details = model.getDetails();
}

void WireframeModel::transform(const Point& move_params, const Point& scale_params, const Point& rotate_params) {
    this->details->transform(move_params, scale_params, rotate_params);
}

void WireframeModel::accept(std::shared_ptr<Visitor> visitor) {
    visitor->visit(*this);
}

const std::shared_ptr<WireframeModelDetails> WireframeModel::getDetails() const {
    return this->details;
}
