#ifndef __LAB_03_MOVE_CAMERA_HPP__
#define __LAB_03_MOVE_CAMERA_HPP__


#include <cstddef>
#include "../camera_command.hpp"
#include "../../../objects/object.hpp"
#include "../../../managers/transform/transform_manager.hpp"

class MoveCamera : public CameraCommand {
    using Action = void(TransformManager::*)(const std::shared_ptr<Object> &obj, const Point &move_params, const Point &scale_params,
                        const Point &rotate_params);
public:
    MoveCamera() = delete;

    MoveCamera(std::shared_ptr<Object> camera, double shift_x, double shift_y);

    ~MoveCamera() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::shared_ptr<Object> camera;
    double shift_x, shift_y;

    Action method;
    std::shared_ptr<TransformManager> manager;
};

#endif //__LAB_03_MOVE_CAMERA_HPP__
    