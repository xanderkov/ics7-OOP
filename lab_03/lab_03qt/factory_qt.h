#ifndef FACTORY_QT_H
#define FACTORY_QT_H

#include "factory_abstract.h"
#include "drawer_qt.h"

class QtFactory : public AbstractFactory
{
public:
    std::shared_ptr<BaseDrawer> CreateUi() const override { return std::make_shared<QtDrawer>(); };
};

#endif // FACTORY_QT_H
