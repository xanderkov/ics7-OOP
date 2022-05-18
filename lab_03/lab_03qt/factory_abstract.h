#ifndef FACTORY_ABSTRACT_H
#define FACTORY_ABSTRACT_H

#include <memory>

#include "drawer_base.h"

class AbstractFactory
{
public:
    virtual std::shared_ptr<BaseDrawer> CreateUi() const = 0;
};

#endif // FACTORY_ABSTRACT_H
