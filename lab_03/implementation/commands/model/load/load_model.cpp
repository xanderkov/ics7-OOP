#include "../../../managers/manager_creator.hpp"
#include "../../../exceptions/load_exceptions.hpp"
#include "../../../facade/facade.hpp"
#include "load_model.hpp"
#include <fstream>


#define CONFIG_MODEL_PATH "../../../../data/configuration/WireframeModelDirector.cfg"

LoadModel::LoadModel(std::shared_ptr<Object> &model, std::string filename) : filename(filename), model(model) {
    this->director_id = 2;
}

void LoadModel::init(Facade &facade) {
    this->manager = facade.getLoadManager();
    this->method = &LoadManager::load;
}

void LoadModel::execute() {
    model = ((*manager).*method)(filename, director_id);
}