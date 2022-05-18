#ifndef COMMANDS_H
#define COMMANDS_H

#include "command_base.h"
#include "controller.h"
#include "factory_abstract.h"
#include "drawer_base.h"
#include "model_source_loader_base.h"
#include "camera_source_loader_base.h"

class AddCameraCommand : public BaseCommand
{
public:
    explicit AddCameraCommand(std::string model_name, std::string file_name, std::shared_ptr<BaseCameraSourceLoader> loader);
    void Run(std::shared_ptr<Controller> controller) override;
private:
    std::shared_ptr<BaseCameraSourceLoader> source_loader;
    std::string camera_name;
    std::string file_name;
};

class AddModelCommand : public BaseCommand
{
public:
    explicit AddModelCommand(std::string model_name, std::string file_name, std::shared_ptr<BaseModelSourceLoader> loader);

    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::shared_ptr<BaseModelSourceLoader> source_loader;
    std::string model_name;
    std::string file_name;
};


class RemoveObjectCommand : public BaseCommand
{
public:
    RemoveObjectCommand(std::string object_name);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string _object_name;
};

class TransformObjectCommand : public BaseCommand
{
public:
    TransformObjectCommand(std::string object_name, Point<double> &move, Point<double> &scale, Point<double> &rotate);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string _object_name;
    Point<double> _move;
    Point<double> _scale;
    Point<double> _rotate;
};

class DrawCommand : public BaseCommand
{
public:
    explicit DrawCommand(std::shared_ptr<BaseDrawer> drawer);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<AbstractFactory> _factory;
};

class SetCameraCommand : public BaseCommand
{
public:
    explicit SetCameraCommand(std::string name);
    void Run(std::shared_ptr<Controller> Controller) override;

private:
    std::string _name;
};

#endif // COMMANDS_H
