#ifndef __LAB_03_MODEL_DIRECTOR_HPP__
#define __LAB_03_MODEL_DIRECTOR_HPP__

#include "../load_director.hpp"

class ModelDirector : public LoadDirector {
public:
    ModelDirector() = default;

    ~ModelDirector() = default;

    virtual std::shared_ptr<Object> load(const std::string &src_name) = 0;
};


#endif //__LAB_03_MODEL_DIRECTOR_HPP__
