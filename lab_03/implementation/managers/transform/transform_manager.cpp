#include "transform_manager.hpp"

void TransformManager::transform(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                            const Point &rotate_params) {
    obj->transform(move_params, scale_params, rotate_params);
}
