#pragma once

#include <memory>
#include "../../../../objects/camera/camera.hpp"
#include "../../../loaders/camera/file_camera_loader.hpp"
#include "../camera_builder.hpp"
//#include "implementation/objects/model/wireframe_model/model_details/point/point.hpp"

class FileCameraBuilder : public CameraBuilder {
public:
    FileCameraBuilder();

    ~FileCameraBuilder() = default;

    void reset();

    std::shared_ptr<Object> get();

    void buildPosition(Point);

    virtual void buildPoint(Point) {}

    virtual void buildEdge(Edge) {}
    
    virtual void buildCenter(Point) {}

private:
    std::shared_ptr<Camera> camera;
};