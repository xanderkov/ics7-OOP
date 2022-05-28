#ifndef __LAB_03_GET_MAIN_CAMERA_HPP__
#define __LAB_03_GET_MAIN_CAMERA_HPP__

#include <cstddef>
#include "../scene_command.hpp"
#include "../../../scene/scene.hpp"
#include "../../../managers/scene/scene_manager.hpp"

class GetMainCamera : public SceneCommand {
    using Action = std::shared_ptr<Camera>(SceneManager::*)() const;
public:
    explicit GetMainCamera(std::shared_ptr<Camera> &camera);

    ~GetMainCamera() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::shared_ptr<Camera> &camera;

    Action method;
    std::shared_ptr<SceneManager> manager;
};
#endif //__LAB_03_GET_MAIN_CAMERA_HPP__