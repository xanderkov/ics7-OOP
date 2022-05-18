#include "facade.h"

Facade::Facade() : controller(Controller::GetInstance()) {}

Facade::~Facade()
{
    controller.reset();
}

void Facade::RunCommand(std::shared_ptr<BaseCommand> command)
{
    command->Run(controller);
}
