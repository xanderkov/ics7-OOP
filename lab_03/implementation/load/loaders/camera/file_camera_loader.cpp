#include "file_camera_loader.hpp"

#include "../../../exceptions/load_exceptions.hpp"


void FileCameraLoader::openFile(const std::string &src_name) {
    this->src_file = std::make_shared<std::ifstream>(src_name);

    if (!*(this->src_file)) throw FileOpenError(__FILE__, __LINE__, "could not open camera-file");
}

Point FileCameraLoader::loadPoint() {
    double x, y, z;
    if (!(*(this->src_file) >> x >> y >> z)) throw FileFormatError(__FILE__, __LINE__, "bad format of camera-file");

    return Point(x, y, z);
}

void FileCameraLoader::closeFile() {
    this->src_file->close();
}
