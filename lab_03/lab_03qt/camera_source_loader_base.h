#ifndef CAMERA_SOURCE_LOADER_BASE_H
#define CAMERA_SOURCE_LOADER_BASE_H

#include "point.h"

class BaseCameraSourceLoader
{
public:
    BaseCameraSourceLoader() = default;
    ~BaseCameraSourceLoader() noexcept = default;

    virtual void open(std::string source_name) = 0;
    virtual void close() = 0;

    virtual bool IsOpen() const = 0;

    virtual Point<double> ReadPosition() = 0;
    virtual Point<double> ReadAngles() = 0;
};

#endif // CAMERA_SOURCE_LOADER_BASE_H
