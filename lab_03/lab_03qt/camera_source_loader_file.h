#ifndef CAMERA_SOURCE_LOADER_FILE_H
#define CAMERA_SOURCE_LOADER_FILE_H

#include <fstream>

#include "camera_source_loader_base.h"

class FileCameraSourceLoader : public BaseCameraSourceLoader
{
public:
    FileCameraSourceLoader() = default;
    ~FileCameraSourceLoader();

    void open(std::string source_name) override;
    void close() override;

    bool IsOpen() const override;
    Point<double> ReadPosition() override;
    Point<double> ReadAngles() override;

private:
    std::ifstream file_;
};

#endif // CAMERA_SOURCE_LOADER_FILE_H
