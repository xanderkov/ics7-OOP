#ifndef __LAB_03_ROTATE_MODEL_HPP__
#define __LAB_03_ROTATE_MODEL_HPP__

#include <cstddef>
#include "../model_command.hpp"
#include "../../../objects/object.hpp"
#include "../../../managers/transform/transform_manager.hpp"

class RotateModel : public ModelCommand {
        using Action = void(TransformManager::*)(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                            const Point &rotate_params);
public:
    RotateModel() = delete;

    RotateModel(std::shared_ptr<Object> model, double ax, double ay, double az);

    ~RotateModel() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::shared_ptr<Object> model;

    double ax, ay, az;
    Action method;
    std::shared_ptr<TransformManager> manager;
};



#endif //__LAB_03_ROTATE_MODEL_HPP__
