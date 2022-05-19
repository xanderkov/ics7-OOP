#include <ctime>

#include "model_source_loader_file.h"
#include "vector.h"
#include "error_loader.h"

FileModelSourceLoader::~FileModelSourceLoader()
{
    close();
}

void FileModelSourceLoader::open(std::string source_name)
{
    if (IsOpen())
        close();

    time_t t_time = time(NULL);
    _file.open(source_name);

    if (!_file)
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}


bool FileModelSourceLoader::IsOpen() const
{
    return _file.is_open();
}

void FileModelSourceLoader::close()
{
    _file.close();
    _file.clear();
}

Vector<Point<double>> FileModelSourceLoader::ReadPoints()
{
    time_t t_time = time(NULL);

    if (!IsOpen())
        throw ReadStreamError(__FILE__, typeid(*this).name, __LINE__, ctime(&t_time));

    Vector<Point<double>> points(n_points, Point<double>(0, 0, 0));

    for (size_t i = 0; i < n_points; ++i)
        if (!(_file >> points[i]))
            throw FileFormatError(__FILE__, typeis(*this).name(), __LINE__, ctime(&t_time));
    return points;
}

Vector<Link> FileModelSourceLoader::ReadLinks()
{
    time_t t_time = time(NULL);

    if (!IsOpen())
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    size_t n_links = 0;
    file_ >> n_links;

    if (n_links < 1)
    {
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Vector<Link> links(n_links, Link());

    for (size_t i = 0; i < n_links; ++i)
    {
        if (!(file_ >> links[i]))
        {
            throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }
    }

    return links;
}

Point<double> FileModelSourceLoader::ReadCentre()
{
    time_t t_time = time(NULL);

    if (!IsOpen())
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    Point<double> centre;

    if (!(file_ >> centre))
    {
        throw FileFormatError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    return centre;
}
