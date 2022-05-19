#ifndef MANAGER_LOAD_H
#define MANAGER_LOAD_H


#include <memory>
#include "load_controller_base.hpp"
#include "model_source_loader_base.hpp"
#include "manager_base.hpp"

class LoadManager : public BaseManager
{
public:
    LoadManager();

    virtual std::shared_ptr<SceneObject> load(std::string model_name, std::string source_name);
    virtual void set_loader(std::shared_ptr<BaseLoadController> lloader);

private:
    std::shared_ptr<BaseLoadController> loader;
};

#endif // MANAGER_LOAD_H
