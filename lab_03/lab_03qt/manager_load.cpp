#include "manager_load.h"

LoadManager::LoadManager(){}

void LoadManager::set_loader(std::shared_ptr<BaseLoadController> lloader)
{
    loader = lloader;
}

std::shared_ptr<SceneObject> LoadManager::load(std::string model_name, std::string source_name)
{

    return loader->load(model_name, source_name);
}
