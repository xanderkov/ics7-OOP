#ifndef SCENE_H
#define SCENE_H

#include <memory>

#include "object_composite.h"

class Scene
{
public:
    Scene();

    void Add(std::shared_ptr<SceneObject> object);
    void Remove(IteratorObject &iter);
    std::shared_ptr<SceneObject> GetObject(std::string object);
    std::shared_ptr<CompositeObject> GetObject();

private:
    std::shared_ptr<CompositeObject> _object;
};

#endif // SCENE_H
