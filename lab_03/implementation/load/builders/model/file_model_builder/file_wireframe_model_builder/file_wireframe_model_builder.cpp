#include "file_wireframe_model_builder.hpp"

#include <fstream>
#include "../../../../../exceptions/load_exceptions.hpp"

FileWireframeModelBuilder::FileWireframeModelBuilder() {}

void FileWireframeModelBuilder::reset() {
    this->model_details = std::make_shared<WireframeModelDetails>();
}

std::shared_ptr<Object> FileWireframeModelBuilder::get() {
    std::shared_ptr<Object> model = std::make_shared<WireframeModel>(this->model_details);
    return model;
}

void FileWireframeModelBuilder::buildPoint(Point p) {
    this->model_details->addPoint(p);
}

void FileWireframeModelBuilder::buildEdge(Edge e) {
        this->model_details->addEdge(e);
}

void FileWireframeModelBuilder::buildCenter(Point c) {
    this->model_details->setCenter(c);
}
