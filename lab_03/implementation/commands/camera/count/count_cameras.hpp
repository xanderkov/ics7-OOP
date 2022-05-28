#ifndef __LAB_03_COUNT_CAMERAS_HPP__
#define __LAB_03_COUNT_CAMERAS_HPP__

#include <memory>
#include <cstddef>

#include "../camera_command.hpp"
#include "../../../managers/scene/scene_manager.hpp"

class CountCameras : public CameraCommand {
    using Action = size_t(SceneManager::*)() const;
public:
    CountCameras() = delete;

    explicit CountCameras(std::shared_ptr<std::size_t> &count);

    ~CountCameras() override = default;

    void init(Facade &facade);

    void execute() override;
 
private:
    std::shared_ptr<std::size_t> &count;
    Action method;
    std::shared_ptr<SceneManager> manager;
};


#endif //__LAB_03_COUNT_CAMERAS_HPP__
