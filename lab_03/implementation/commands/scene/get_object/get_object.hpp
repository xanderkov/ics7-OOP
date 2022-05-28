#ifndef __LAB_03_GET_OBJECT_HPP__
#define __LAB_03_GET_OBJECT_HPP__

#include <cstddef>
#include "../scene_command.hpp"
#include "../../../scene/scene.hpp"
#include "../../../managers/scene/scene_manager.hpp"

class GetSceneObject : public SceneCommand {
    using Action = std::shared_ptr<Object>(SceneManager::*)(size_t id);
public:
    GetSceneObject() = delete;

    explicit GetSceneObject(std::shared_ptr<Object> &object, size_t id);

    ~GetSceneObject() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::shared_ptr<Object> &object;
    std::size_t id;

    Action method;
    std::shared_ptr<SceneManager> manager;
};
#endif //__LAB_03_GET_OBJECT_HPP__