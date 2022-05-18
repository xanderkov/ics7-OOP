#ifndef ERROR_DRAWER_H
#define ERROR_DRAWER_H

#include "error_base.h"
#include "error_scene.h"

class DrawerError : public BaseError
{
public:
    DrawerError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Drawer wasn't set") : BaseError(filename, classname, line, time, info) {}
};

#endif // ERROR_DRAWER_H
