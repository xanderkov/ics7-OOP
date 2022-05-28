#ifndef __LAB_03_WIREFRAME_MODEL_HPP__
#define __LAB_03_WIREFRAME_MODEL_HPP__

#include <memory>
#include "../model.hpp"
#include "../../../visitor/draw_visitor/draw_visitor.hpp"
#include "model_details/wireframe_model_details.hpp"
#include "../../object.hpp"

class WireframeModel : public Model {
public:
    WireframeModel();

    explicit WireframeModel(std::shared_ptr<WireframeModelDetails> details);

    WireframeModel(const WireframeModel& model);

    ~WireframeModel() override = default;

    void transform(const Point& move_params, const Point& scale_params, const Point& rotate_params) override;

    void accept(std::shared_ptr<Visitor> visitor) override;

    friend void DrawVisitor::visit(const WireframeModel& model);

protected:
    [[nodiscard]] const std::shared_ptr<WireframeModelDetails> getDetails() const;

private:
    std::shared_ptr<WireframeModelDetails> details;
};


#endif //__LAB_03_WIREFRAME_MODEL_HPP__
