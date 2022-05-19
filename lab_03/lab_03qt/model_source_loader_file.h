#ifndef MODEL_SOURCE_LOADER_FILE_H
#define MODEL_SOURCE_LOADER_FILE_H

#include <fstream>

#include "vector.h"
#include "link.h"
#include "model_source_loader_base.h"

class FileModelSourceLoader : public BaseModelSourceLoader
{
public:
    FileModelSourceLoader() = default;
    ~FileModelSourceLoader();

    void open(std::string source_name) override;
    void close() override;

    bool IsOpen() const override;
    Vector<Point<double>> ReadPoints() override;
    Vector<Link> ReadLinks() override;
    Point<double> ReadCentre() override;

private:
    std::ifstream _file;
};


#endif // MODEL_SOURCE_LOADER_FILE_H
