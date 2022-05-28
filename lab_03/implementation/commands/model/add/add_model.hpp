#ifndef __LAB_03_ADD_MODEL_HPP__
#define __LAB_03_ADD_MODEL_HPP__

#include <memory>
#include "../model_command.hpp"
#include "../../../objects/object.hpp"
#include "../../../managers/scene/scene_manager.hpp"

class AddModel : public ModelCommand {
    using Action = void(SceneManager::*)(const std::shared_ptr<Object> &);
public:
    AddModel() = delete;

    explicit AddModel(std::shared_ptr<Object> model);

    ~AddModel() override = default;

    void init(Facade &facade);
 
    void execute() override;

private:
    std::shared_ptr<Object> model;
    Action method;
    std::shared_ptr<SceneManager> manager;
};


#endif //__LAB_03_ADD_MODEL_HPP__
