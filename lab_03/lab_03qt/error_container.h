#ifndef ERROR_CONTAINER_H
#define ERROR_CONTAINER_H

#include "error_base.h"

class MemError : public BaseError
{
public:
    MemError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Memory allocation error") : BaseError(filename, classname, line, time, info) {}
};

class RangeError : public BaseError
{
public:
    RangeError(
        const std::string &filename,
        const std::string &classname,
        const int line,
        const char *time,
        const std::string &info = "Range error") : BaseError(filename, classname, line, time, info) {}
};


#endif // ERROR_CONTAINER_H
