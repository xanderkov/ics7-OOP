#pragma once

#include <string>
#include "../../objects/object.hpp"

class ObjectBuilder {
public:
    ObjectBuilder() = default;

    virtual ~ObjectBuilder() = default;

    virtual void reset() = 0;

    virtual std::shared_ptr<Object> get() = 0;

    virtual void buildPoint(Point) = 0;

    virtual void buildEdge(Edge) = 0;
    
    virtual void buildCenter(Point) = 0;

    virtual void buildPosition(Point) = 0;
};
