#ifndef __LAB_03_REMOVE_CAMERA_HPP__
#define __LAB_03_REMOVE_CAMERA_HPP__


#include <cstddef>
#include "../camera_command.hpp"
#include "../../../managers/scene/scene_manager.hpp"

class RemoveCamera : public CameraCommand {
    using Action = void(SceneManager::*)(size_t);
public:
    RemoveCamera() = delete;

    explicit RemoveCamera(std::size_t camera_id);

    ~RemoveCamera() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::size_t camera_id;
    Action method;
    std::shared_ptr<SceneManager> manager;
};

#endif //__LAB_03_REMOVE_CAMERA_HPP__
