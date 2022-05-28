#include "../../../managers/manager_creator.hpp"
#include "../../../exceptions/load_exceptions.hpp"
#include "../../../facade/facade.hpp"
#include "load_model.hpp"
#include <fstream>


#define CONFIG_MODEL_PATH "../../../../data/configuration/WireframeModelDirector.cfg"

LoadModel::LoadModel(std::shared_ptr<Object> &model, std::string filename) : filename(filename), model(model) {
    /*std::string src_name = CONFIG_MODEL_PATH;
    std::shared_ptr<std::ifstream> src_file = std::make_shared<std::ifstream>(src_name);
    if (!(*(src_file))) throw FileOpenError(__FILE__, __LINE__, "could not open config file!");

    size_t id = 0;
    if (!(*(src_file) >> id)) throw FileFormatError(__FILE__, __LINE__, "bad format of config file");
    this->director_id = id;

    src_file->close();*/
    this->director_id = 2;
}

void LoadModel::init(Facade &facade) {
    this->manager = facade.getLoadManager();
    this->method = &LoadManager::load;
}

void LoadModel::execute() {
    model = ((*manager).*method)(filename, director_id);
}