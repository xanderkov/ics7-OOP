#ifndef MODEL_SOURCE_LOADER_BASE_H
#define MODEL_SOURCE_LOADER_BASE_H

#include "vector.h"
#include "link.h"
#include "point.h"

class BaseModelSourceLoader
{
public:
    BaseModelSourceLoader() = default;
    ~BaseModelSourceLoader() noexcept = default;

    virtual void open(std::string source_name) = 0;
    virtual void close() = 0;

    virtual bool IsOpen() const = 0;

    virtual Vector<Point<double>> ReadPoints() = 0;
    virtual Vector<Link> ReadLinks() = 0;
    virtual Point<double> ReadCentre() = 0;
};

#endif // MODEL_SOURCE_LOADER_BASE_H
