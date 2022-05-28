#ifndef __LAB_03_SET_CAMERA_HPP__
#define __LAB_03_SET_CAMERA_HPP__

#include <cstddef>
#include "../camera_command.hpp"

class SetCamera : public CameraCommand {
    using Action = void(SceneManager::*)(size_t camera_id);
public:
    SetCamera() = delete;

    explicit SetCamera(size_t camera_id);

    ~SetCamera() override = default;

    void init(Facade &facade);

    void execute() override;
 

private:
    std::size_t camera_id;
    Action method;
    std::shared_ptr<SceneManager> manager;
};

#endif //__LAB_03_SET_CAMERA_HPP__
