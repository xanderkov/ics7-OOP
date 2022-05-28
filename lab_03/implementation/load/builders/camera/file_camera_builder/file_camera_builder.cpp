#include "file_camera_builder.hpp"

#include <fstream>
#include "../../../../exceptions/load_exceptions.hpp"

FileCameraBuilder::FileCameraBuilder() {}

void FileCameraBuilder::reset() {
    this->camera = std::make_shared<Camera>();
}

std::shared_ptr<Object> FileCameraBuilder::get() {
    return this->camera;
}

void FileCameraBuilder::buildPosition(Point pos) {
    this->camera->transform(pos, Point(1, 1, 1), Point(0, 0, 0));
}
