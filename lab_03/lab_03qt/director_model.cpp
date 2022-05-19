#include "director_model.h"
#include <memory>

void ModelDirector::SetBuilder(std::shared_ptr<BaseModelBuilder> builder)
{
    builder_ = std::move(builder);
}

std::shared_ptr<Model> ModelDirector::Build(const Vector<Point<double>> &points, const Vector<Link> &links, const Point<double> centre)
{
    builder_->BuildPoints(points);
    builder_->BuildLinks(links);
    builder_->BuildCentre(centre);

    return builder_->GetModel();
}
