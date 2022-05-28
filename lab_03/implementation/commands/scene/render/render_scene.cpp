#include "../../../managers/manager_creator.hpp"
#include "../../../facade/facade.hpp"
#include <utility>
#include "render_scene.hpp"

RenderScene::RenderScene(std::shared_ptr<Scene> &scene, std::shared_ptr<Drawer> drawer, std::shared_ptr<Camera> mainCamera) 
                                    : scene(scene), drawer(drawer), mainCamera(mainCamera) {}

void RenderScene::init(Facade &facade) {
    this->manager = facade.getDrawManager();
    this->method = &DrawManager::draw;
}

void RenderScene::execute() {
    ((*manager).*method)(scene, drawer, mainCamera);
}
