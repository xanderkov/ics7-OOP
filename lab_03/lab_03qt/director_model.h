#ifndef DIRECTOR_MODEL_H
#define DIRECTOR_MODEL_H

#include <memory>

#include "builder_model_base.h"
#include "model_source_loader_base.h"
#include "object_model.h"

class ModelDirector
{
public:
    std::shared_ptr<Model> Build(const Vector<Point<double>> &points, const Vector<Link> &links, const Point<double> centre);
    void SetBuilder(std::shared_ptr<BaseModelBuilder> builder);

private:
    std::shared_ptr<BaseModelBuilder> builder_;
};

#endif // DIRECTOR_MODEL_H
