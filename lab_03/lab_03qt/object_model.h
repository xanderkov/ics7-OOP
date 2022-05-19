#ifndef OBJECT_MODEL_H
#define OBJECT_MODEL_H

#include "link.h"
#include "point.h"
#include "carcass.h"
#include "object_visible.h"
#include "matrix.h"
#include "vector.h"
#include "visitor.h"

class Model : public VisibleObject
{
public:
    Model() = default;
    explicit Model(std::string name);
    Model(const Model &other);
    Model(Model &&other) noexcept;
    Model &operator=(const Model &other);
    Model &operator=(Model &&other) noexcept;
    ~Model() = default;

    void Transform(const std::shared_ptr<Matrix<double>> mtr) override;
    void Accept(std::shared_ptr<Visitor> visitor) override;

    friend class DrawManager;
    friend class ModelBuilder;

private:
    std::shared_ptr<Carcass> _carcass;
};

#endif // OBJECT_MODEL_H
