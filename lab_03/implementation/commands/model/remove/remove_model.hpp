#ifndef __LAB_03_REMOVE_MODEL_HPP__
#define __LAB_03_REMOVE_MODEL_HPP__


#include <cstddef>
#include "../model_command.hpp"
#include "../../../managers/scene/scene_manager.hpp"

class RemoveModel : public ModelCommand {
    using Action = void(SceneManager::*)(size_t);
public:
    RemoveModel() = delete;

    explicit RemoveModel(size_t model_id);

    ~RemoveModel() override = default;

    void init(Facade &facade);

    void execute() override;

private:
    std::size_t model_id;
    Action method;
    std::shared_ptr<SceneManager> manager;
};


#endif //__LAB_03_REMOVE_MODEL_HPP__
