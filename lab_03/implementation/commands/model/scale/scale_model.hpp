#ifndef __LAB_03_SCALE_MODEL_HPP__
#define __LAB_03_SCALE_MODEL_HPP__


#include <cstddef>
#include "../model_command.hpp"
#include "../../../objects/object.hpp"
#include "../../../managers/transform/transform_manager.hpp"

class ScaleModel : public ModelCommand {
    using Action = void(TransformManager::*)(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                            const  Point &rotate_params);
public:
    ScaleModel() = delete;

    ScaleModel(std::shared_ptr<Object> model, double kx, double ky, double kz);

    ~ScaleModel() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::shared_ptr<Object> model;

    double kx, ky, kz;
    Action method;
    std::shared_ptr<TransformManager> manager;
};

#endif //__LAB_03_SCALE_MODEL_HPP__
