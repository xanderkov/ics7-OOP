#ifndef __LAB_03_TRANSFORM_MODEL_HPP__
#define __LAB_03_TRANSFORM_MODEL_HPP__


#include <cstddef>
#include "../model_command.hpp"
#include "../../../objects/object.hpp"
#include "../../../managers/transform/transform_manager.hpp"

class TransformModel : public ModelCommand {
    using Action = void(TransformManager::*)(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                            const Point &rotate_params);
public:
    TransformModel() = delete;

    TransformModel(std::shared_ptr<Object> model, const Point &move, const Point &scale, const Point &rotate);

    ~TransformModel() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::shared_ptr<Object> model;

    Point move, scale, rotate;
    Action method;
    std::shared_ptr<TransformManager> manager;
};

#endif //__LAB_03_TRANSFORM_MODEL_HPP__
