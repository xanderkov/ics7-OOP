#ifndef __LAB_03_LOAD_MODEL_HPP__
#define __LAB_03_LOAD_MODEL_HPP__


#include <string>
#include "../model_command.hpp"
#include "../../../objects/object.hpp"
#include "../../../managers/load/load_manager.hpp"

class LoadModel : public ModelCommand {
    using Action = std::shared_ptr<Object> (LoadManager::*)(const std::string &name, size_t director_id);
public:
    LoadModel() = delete;

    explicit LoadModel(std::shared_ptr<Object> &model, std::string filename);

    ~LoadModel() override = default;

    void init(Facade &facade) override;

    void execute() override;

private:
    std::shared_ptr<Object> &model;
    std::string filename;
    size_t director_id;

    Action method;
    std::shared_ptr<LoadManager> manager;
};


#endif //__LAB_03_LOAD_MODEL_HPP__
