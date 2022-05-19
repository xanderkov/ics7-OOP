#ifndef OBJECT_SCENE_H
#define OBJECT_SCENE_H

#include <cstdio>

#include "matrix.h"
#include "iterator_vector.h"
#include "vector.h"
#include "visitor.h"

class SceneObject;

using VectorObject = Vector<std::shared_ptr<SceneObject>>;
using IteratorObject = VectorObject::iterator;

class SceneObject
{
public:
    SceneObject() = default;
    SceneObject(std::string name) : _name(name){};
    ~SceneObject() = default;

    virtual bool IsVisible() const = 0;
    virtual bool IsComposite() const { return false; }
    virtual bool Add(std::shared_ptr<SceneObject> obj) { return false; }
    virtual bool Remove(IteratorObject &iter) { return false; }
    virtual void Transform(std::shared_ptr<Matrix<double>> Matrix) = 0;
    virtual void Accept(std::shared_ptr<Visitor> visitor) = 0; // для visitor
    virtual std::string GetName() { return _name; }

    virtual IteratorObject begin() { return IteratorObject(); }
    virtual IteratorObject end() { return IteratorObject(); }

protected:
    std::string _name;
};

#endif // OBJECT_SCENE_H
