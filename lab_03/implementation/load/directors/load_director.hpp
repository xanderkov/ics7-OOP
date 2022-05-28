#ifndef __LAB_03_LOAD_DIRECTOR_HPP__
#define __LAB_03_LOAD_DIRECTOR_HPP__


#include <memory>
#include <utility>

#include "../../load/loaders/file_base_loader.hpp"
#include "../../load/builders/object_builder.hpp"
#include "../../objects/object.hpp"


class LoadDirector {
public:
    LoadDirector() = default;

    ~LoadDirector() = default;

    virtual std::shared_ptr<Object> load(const std::string &name) = 0;

protected:
    std::shared_ptr<ObjectBuilder> builder;
    std::shared_ptr<FileBaseLoader> loader;
};

#endif //__LAB_03_LOAD_DIRECTOR_HPP__
