#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "controller.h"

class BaseCommand
{
public:
    BaseCommand() = default;
    ~BaseCommand() = default;

    virtual void Run(std::shared_ptr<Controller> controller) = 0;
};

#endif // COMMAND_BASE_H
