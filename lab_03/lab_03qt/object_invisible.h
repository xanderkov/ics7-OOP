#ifndef OBJECT_INVISIBLE_H
#define OBJECT_INVISIBLE_H

#include "object_scene.h"

class InvisibleObject : public SceneObject
{
public:
    explicit InvisibleObject() = default;
    ~InvisibleObject() = default;

    bool IsVisible() const { return false; }
};


#endif // OBJECT_INVISIBLE_H
