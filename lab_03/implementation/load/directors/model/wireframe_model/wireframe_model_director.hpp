#ifndef __LAB_03_WIREFRAME_MODEL_DIRECTOR_HPP__
#define __LAB_03_WIREFRAME_MODEL_DIRECTOR_HPP__

#include "../model_director.hpp"
#include "../../../../load/builders/model/file_model_builder/file_wireframe_model_builder/file_wireframe_model_builder.hpp"

class WireframeModelDirector : public ModelDirector {
public:
    WireframeModelDirector();
    ~WireframeModelDirector() = default;

    std::shared_ptr<Object> load(const std::string &src_name) override;
private:
    void loadPoints();
    void loadEdges();
    void loadCenter();
};


#endif //__LAB_03_WIREFRAME_MODEL_DIRECTOR_HPP__
