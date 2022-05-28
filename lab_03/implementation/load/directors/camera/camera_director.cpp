#include "camera_director.hpp"

CameraDirector::CameraDirector() {
    this->builder = std::make_shared<FileCameraBuilder>();
    this->loader = std::make_shared<FileCameraLoader>();
}

std::shared_ptr<Object> CameraDirector::load(const std::string &src_name) {
    this->builder->reset();
    this->loader->openFile(src_name);
 
    Point pos = this->loader->loadPoint();
    this->builder->buildPosition(pos);

    this->loader->closeFile();

    decltype(auto) camera = this->builder->get();

    return camera;
}
