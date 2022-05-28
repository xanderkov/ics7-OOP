#ifndef __LAB_03_RENDER_SCENE_HPP__
#define __LAB_03_RENDER_SCENE_HPP__



#include "../scene_command.hpp"
#include "../../../drawer/drawer.hpp"
#include "../../../managers/draw/draw_manager.hpp"
#include "../../../scene/scene.hpp"
#include "../../../objects/camera/camera.hpp"

class RenderScene : public SceneCommand {
        using Action = void(DrawManager::*)(const std::shared_ptr<Scene> &scene, 
                                            const std::shared_ptr<Drawer> drawer, const std::shared_ptr<Camera> camera);
public:
    RenderScene() = delete;

    explicit RenderScene(std::shared_ptr<Scene> &scene, std::shared_ptr<Drawer> drawer, std::shared_ptr<Camera> mainCamera);

    void init(Facade &facade);

    void execute() override;

    ~RenderScene() override = default;

private:
    std::shared_ptr<Drawer> drawer;
    std::shared_ptr<Scene> &scene;
    std::shared_ptr<Camera> mainCamera;
    
    Action method;
    std::shared_ptr<DrawManager> manager;
};


#endif //__LAB_03_RENDER_SCENE_HPP__
