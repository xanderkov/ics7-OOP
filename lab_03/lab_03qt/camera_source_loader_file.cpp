#include <ctime>

#include "camera_source_loader_file.h"
#include "error_loader.h"

FileCameraSourceLoader::~FileCameraSourceLoader()
{
    close();
}

void FileCameraSourceLoader::open(std::string source_name)
{
    if (IsOpen())
    {
        close();
    }

    time_t t_time = time(NULL);

    file_.open(source_name);
    if (!file_)
    {
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

bool FileCameraSourceLoader::IsOpen() const
{
    return file_.is_open();
}

void FileCameraSourceLoader::close()
{
    file_.close();
    file_.clear();
}

Point<double> FileCameraSourceLoader::ReadPosition()
{
    time_t t_time = time(NULL);

    if (!IsOpen())
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Point<double> position;

    if (!(file_ >> position))
    {
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    return position;
}

Point<double> FileCameraSourceLoader::ReadAngles()
{
    time_t t_time = time(NULL);

    if (!IsOpen())
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Point<double> angles;

    if (!(file_ >> angles))
    {
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    return angles;
}
