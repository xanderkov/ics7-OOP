#ifndef BUILDER_MODEL_BASE_H
#define BUILDER_MODEL_BASE_H

#include "object_model.h"

class BaseModelBuilder
{
public:
    BaseModelBuilder() = default;
    ~BaseModelBuilder() = default;

    virtual void BuildPoints(const Vector<Point<double>> &points) = 0;
    virtual void BuildLinks(const Vector<Link> &links) = 0;
    virtual void BuildCentre(const Point<double> centre) = 0;
    virtual void reset(std::string name) = 0;
    virtual std::shared_ptr<Model> GetModel() = 0;
};

#endif // BUILDER_MODEL_BASE_H
