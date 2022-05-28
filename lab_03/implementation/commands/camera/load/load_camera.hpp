#ifndef __LAB_03_LOAD_CAMERA_HPP__
#define __LAB_03_LOAD_CAMERA_HPP__


#include <string>
#include "../camera_command.hpp"
#include "../../../objects/object.hpp"
#include "../../../managers/load/load_manager.hpp"

class LoadCamera : public CameraCommand {
    using Action = std::shared_ptr<Object> (LoadManager::*)(const std::string &name, size_t director_id);
public:
    LoadCamera() = delete;

    explicit LoadCamera(std::shared_ptr<Object> &camera, std::string filename);

    ~LoadCamera() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::shared_ptr<Object> &camera;
    std::string filename;
    size_t director_id;

    Action method;
    std::shared_ptr<LoadManager> manager;
};


#endif //__LAB_03_LOAD_CAMERA_HPP__
