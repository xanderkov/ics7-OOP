#include "builder_model.h"

void ModelBuilder::BuildPoints(const Vector<Point<double>> &points)
{
    model->_carcass->GetPoints() = points;
}

void ModelBuilder::reset(std::string name)
{
    model.reset();
    model = std::shared_ptr<Model>(std::make_shared<Model>(name));
}

void ModelBuilder::BuildLinks(const Vector<Link> &links)
{
    model->_carcass->GetLinks() = links;
}

void ModelBuilder::BuildCentre(const Point<double> centre)
{
    model->_carcass->GetCentre() = centre;
}

std::shared_ptr<Model> ModelBuilder::GetModel()
{
    return model;
}
