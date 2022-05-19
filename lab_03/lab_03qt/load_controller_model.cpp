#include "load_controller_model.h"
#include "director_model.h"
#include <memory.h>

ModelLoadController::ModelLoadController(std::shared_ptr<BaseModelBuilder> bld, std::shared_ptr<BaseModelSourceLoader> source_loader)
{
    builder_ = bld;
    source_loader_ = source_loader;
}

std::shared_ptr<SceneObject> ModelLoadController::load(std::string model_name, std::string source_name)
{
    source_loader_->open(source_name);
    builder_->reset(model_name);

    Vector<Point<double>> points = this->source_loader_->ReadPoints();
    Vector<Link> links = this->source_loader_->ReadLinks();
    Point<double> centre = this->source_loader_->ReadCentre();
    source_loader_->close();

    ModelDirector director;
    director.SetBuilder(builder_);

    return director.Build(points, links, centre);
}
