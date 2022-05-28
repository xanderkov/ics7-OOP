#include "file_wireframe_model_loader.hpp"

#include <fstream>
#include "../../../exceptions/load_exceptions.hpp"

void FileWireframeModelLoader::openFile(const std::string &src_name) {
    this->src_file = std::make_shared<std::ifstream>(src_name);
    if (!*(this->src_file)) throw FileOpenError(__FILE__, __LINE__, "could not open model-file");
}

void FileWireframeModelLoader::closeFile() {
    this->src_file->close();
}

Point FileWireframeModelLoader::loadPoint() {
    double x, y, z;
    if (!(*(this->src_file) >> x >> y >> z)) throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
    
    return Point(x, y, z);
}

Edge FileWireframeModelLoader::loadEdge() {
    size_t p1_id, p2_id;
    if (!(*(this->src_file) >> p1_id >> p2_id)) throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
    
    return Edge(p1_id, p2_id);
}


size_t FileWireframeModelLoader::loadCount() {
    size_t count = 0;
    *(this->src_file) >> count;
    if (count <= 1) throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");

    return count;
}
