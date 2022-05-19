#ifndef LOAD_CONTROLLER_MODEL_H
#define LOAD_CONTROLLER_MODEL_H

#include "load_controller_base.h"

class ModelLoadController : public BaseLoadController
{
public:
    ModelLoadController(std::shared_ptr<BaseModelBuilder> bld, std::shared_ptr<BaseModelSourceLoader> source_loader);
    std::shared_ptr<SceneObject> load(std::string model_name, std::string source_name) override;

private:
    std::shared_ptr<BaseModelBuilder> builder_;
    std::shared_ptr<BaseModelSourceLoader> source_loader_;
};

#endif // LOAD_CONTROLLER_MODEL_H
