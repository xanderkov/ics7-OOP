#ifndef __LAB_03_GET_SCENE_HPP__
#define __LAB_03_GET_SCENE_HPP__

#include <cstddef>
#include "../scene_command.hpp"
#include "../../../scene/scene.hpp"
#include "../../../managers/scene/scene_manager.hpp"

class GetScene : public SceneCommand {
    using Action = std::shared_ptr<Scene>(SceneManager::*)() const;
public:

    explicit GetScene(std::shared_ptr<Scene> &scene);

    ~GetScene() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::shared_ptr<Scene> &scene;

    Action method;
    std::shared_ptr<SceneManager> manager;
};
#endif //__LAB_03_GET_SCENE_HPP__