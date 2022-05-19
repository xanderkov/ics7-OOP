#ifndef OBJECT_VISIBLE_H
#define OBJECT_VISIBLE_H

#include "object_scene.h"

class VisibleObject : public SceneObject
{
public:
    explicit VisibleObject() = default;
    ~VisibleObject() = default;

    bool IsVisible() const { return true; }
};

#endif // OBJECT_VISIBLE_H
