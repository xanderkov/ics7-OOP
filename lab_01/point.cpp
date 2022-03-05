#include"point.h"

double get_point_x(point a)
{
    return a.x;
}

double get_point_y(point a)
{
    return a.y;
}

double get_point_z(point a)
{
    return a.z;
}

int get_point_n(point a)
{
    return a.n;
}

void set_point_x(point &a, const double x)
{
    a.x = x;
}
void set_point_y(point &a, const double y)
{
    a.y = y;
}
void set_point_z(point &a, const double z)
{
    a.z = z;
}
void set_point_n(point &a, const int n)
{
    a.n = n;
}

void zero_point(point &a)
{
    a.n = 0;
    a.x = 0;
    a.y = 0;
    a.z = 0;
}

void set_point(point &a, const double x, const double y, const double z, const int n)
{

    a.n = n;
    a.x = x;
    a.y = y;
    a.z = z;
}

void copy_point(point &a, point &b)
{
    a.n = b.n;
    a.x = b.x;
    a.y = b.y;
    a.z = b.z;
}


