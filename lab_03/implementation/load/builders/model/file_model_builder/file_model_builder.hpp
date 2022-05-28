#pragma once

#include "../model_builder.hpp"

class FileModelBuilder : public ModelBuilder {
public:
    FileModelBuilder() = default;

    virtual ~FileModelBuilder() = default;

    virtual void reset() = 0;

    virtual std::shared_ptr<Object> get() = 0;

    virtual void buildPoint(Point) = 0;

    virtual void buildEdge(Edge) = 0;
    
    virtual void buildCenter(Point) = 0;
};
