#ifndef __LAB_03_LOAD_MANAGER_HPP__
#define __LAB_03_LOAD_MANAGER_HPP__


#include <memory>
#include "../../load/directors/load_director.hpp"
#include "../manager.hpp"
#include "../../objects/object.hpp"

class LoadManager : public Manager {
public:
    LoadManager() = default;

    LoadManager(const LoadManager &) = delete;

    LoadManager &operator=(const LoadManager &) = delete;

    ~LoadManager() override = default;

    virtual std::shared_ptr<Object> load(const std::string &name, size_t director_id);

private:
    std::shared_ptr<LoadDirector> director;
};


#endif //__LAB_03_LOAD_MANAGER_HPP__
