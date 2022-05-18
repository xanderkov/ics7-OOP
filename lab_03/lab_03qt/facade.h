#ifndef FACADE_H
#define FACADE_H

#include "command_base.h"
#include "commands.h"
#include "controller.h"
#include "error_base.h"

class Facade
{
public:
    Facade();
    ~Facade();

    void RunCommand(std::shared_ptr<BaseCommand> command);

private:
    std::shared_ptr<Controller> controller;
};

#endif // FACADE_H
