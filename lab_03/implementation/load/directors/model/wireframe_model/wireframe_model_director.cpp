#include "wireframe_model_director.hpp"

WireframeModelDirector::WireframeModelDirector() {
    this->builder = std::make_shared<FileWireframeModelBuilder>();
    this->loader = std::make_shared<FileWireframeModelLoader>();
}

std::shared_ptr<Object> WireframeModelDirector::load(const std::string &src_name) {
    this->builder->reset();
    this->loader->openFile(src_name);

    loadPoints();
    loadCenter();
    loadEdges();

    this->loader->closeFile();

    decltype(auto) model = this->builder->get();

    return model;
}

void WireframeModelDirector::loadPoints() {
    size_t count = loader->loadCount();
    for (int i = 0; i < count; i++)
    {
        Point p = loader->loadPoint();
        builder->buildPoint(p);
    }
}

void WireframeModelDirector::loadEdges() {
    size_t count = loader->loadCount();
    for (int i = 0; i < count; i++)
    {
        Edge e = loader->loadEdge();
        builder->buildEdge(e);
    }
}

void WireframeModelDirector::loadCenter() {
    Point c = loader->loadPoint();
    builder->buildPoint(c);
}
