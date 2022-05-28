#pragma once

#include <memory>
#include <fstream>
#include "../../objects/camera/camera.hpp"
#include "../../objects/model/wireframe_model/model_details/point/point.hpp"
#include "../../objects/model/wireframe_model/model_details/edge/edge.hpp"

class FileBaseLoader {
public:
    FileBaseLoader() = default;

    virtual ~FileBaseLoader() = default;

    virtual void openFile(const std::string &src_name) = 0;
    
    virtual void closeFile() = 0;

    virtual Point loadPoint() = 0;
    
    virtual Edge loadEdge() = 0;

    virtual size_t loadCount() = 0;

private:
    std::shared_ptr<std::ifstream> src_file;
};
