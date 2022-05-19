#ifndef LOAD_CONTROLLER_BASE_H
#define LOAD_CONTROLLER_BASE_H


#include <memory>

#include "builder_model_base.h"
#include "manager_base.h"
#include "object_model.h"
#include "model_source_loader_base.h"

class BaseLoadController
{
public:
    virtual ~BaseLoadController() = default;
    virtual std::shared_ptr<SceneObject> load(std::string name, std::string source_name) = 0;
};

#endif // LOAD_CONTROLLER_BASE_H
