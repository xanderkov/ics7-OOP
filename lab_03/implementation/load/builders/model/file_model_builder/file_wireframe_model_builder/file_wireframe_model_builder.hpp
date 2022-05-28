#pragma once

#include "../../../../../objects/model/wireframe_model/wireframe_model.hpp"
#include "../../../../loaders/model/file_wireframe_model_loader.hpp"
#include "../file_model_builder.hpp"

class FileWireframeModelBuilder : public FileModelBuilder {
public:
    FileWireframeModelBuilder();

    ~FileWireframeModelBuilder() = default;

    void reset();

    std::shared_ptr<Object> get();

    void buildPoint(Point);

    void buildEdge(Edge);
    
    void buildCenter(Point);

    virtual void buildPosition(Point) {}

private:
    std::shared_ptr<WireframeModelDetails> model_details;
};
