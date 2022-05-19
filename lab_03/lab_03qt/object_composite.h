#ifndef OBJECT_COMPOSITE_H
#define OBJECT_COMPOSITE_H

#include <memory>

#include "object_camera.h"
#include "object_model.h"

class CompositeObject : public SceneObject
{
public:
    CompositeObject() = default;

    bool Add(std::shared_ptr<SceneObject> obj) override;
    bool Remove(IteratorObject &iter) override;
    bool IsVisible() const override;
    bool IsComposite() const override;
    void Transform(const std::shared_ptr<Matrix<double>> Matrix) override;
    void Accept(std::shared_ptr<Visitor> visitor) override; // для visitor

    virtual IteratorObject begin() override;
    virtual IteratorObject end() override;

private:
    VectorObject _scene_objects;
};

#endif // OBJECT_COMPOSITE_H
