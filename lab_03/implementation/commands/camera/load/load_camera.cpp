#include "../../../managers/manager_creator.hpp"
#include "../../../exceptions/load_exceptions.hpp"
#include "../../../facade/facade.hpp"
#include "load_camera.hpp"
#include <fstream>

#define CONFIG_CAMERA_PATH "../../../../data/configuration/CameraDirector.cfg"

LoadCamera::LoadCamera(std::shared_ptr<Object> &camera, std::string filename) : filename(filename), camera(camera) {
    this->director_id = 1;
}

void LoadCamera::init(Facade &facade) {
    this->manager = facade.getLoadManager();
    this->method = &LoadManager::load;
}

void LoadCamera::execute() {
    camera = ((*manager).*method)(filename, director_id);
}
