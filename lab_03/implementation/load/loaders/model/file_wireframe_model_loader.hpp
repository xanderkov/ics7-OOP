#ifndef __LAB_03_MODEL_BUILDER_HPP__
#define __LAB_03_MODEL_BUILDER_HPP__

#include <memory>
#include <fstream>
#include "../../../objects/model/wireframe_model/model_details/point/point.hpp"
#include "../../../objects/model/wireframe_model/model_details/edge/edge.hpp"
#include "../file_base_loader.hpp"

class FileWireframeModelLoader : public FileBaseLoader {
public:
    FileWireframeModelLoader() = default;

    ~FileWireframeModelLoader() = default;

    void openFile(const std::string &src_name);
    
    void closeFile();

    Point loadPoint();
    
    Edge loadEdge();

    size_t loadCount();

private:
    std::shared_ptr<std::ifstream> src_file;
};


#endif //__LAB_03_MODEL_BUILDER_HPP__
