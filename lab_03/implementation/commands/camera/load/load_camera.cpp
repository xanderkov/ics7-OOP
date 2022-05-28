#include "../../../managers/manager_creator.hpp"
#include "../../../exceptions/load_exceptions.hpp"
#include "../../../facade/facade.hpp"
#include "load_camera.hpp"
#include <fstream>

#define CONFIG_CAMERA_PATH "../../../../data/configuration/CameraDirector.cfg"

LoadCamera::LoadCamera(std::shared_ptr<Object> &camera, std::string filename) : filename(filename), camera(camera) {
    /*std::string src_name = CONFIG_CAMERA_PATH;
    std::shared_ptr<std::ifstream> src_file = std::make_shared<std::ifstream>(src_name);
    if (!(*(src_file))) throw FileOpenError(__FILE__, __LINE__, "could not open config file!");

    size_t id = 0;
    if (!(*(src_file) >> id)) throw FileFormatError(__FILE__, __LINE__, "bad format of config file");
    this->director_id = id;

    src_file->close();*/
    this->director_id = 1;
}

void LoadCamera::init(Facade &facade) {
    this->manager = facade.getLoadManager();
    this->method = &LoadManager::load;
}

void LoadCamera::execute() {
    camera = ((*manager).*method)(filename, director_id);
}
