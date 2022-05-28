#pragma once

#include "../object_builder.hpp"

class ModelBuilder : public ObjectBuilder {
public:
    ModelBuilder() = default;

    virtual ~ModelBuilder() = default;

    virtual void reset() = 0;

    virtual std::shared_ptr<Object> get() = 0;

    virtual void buildPoint(Point) = 0;

    virtual void buildEdge(Edge) = 0;
    
    virtual void buildCenter(Point) = 0;
};
