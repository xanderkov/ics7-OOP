#include"point.h"

double get_point_x(struct point a)
{
    return a.x;
}

double get_point_y(struct point a)
{
    return a.y;
}

double get_point_z(struct point a)
{
    return a.z;
}

int get_point_n(struct point a)
{
    return a.n;
}

void set_point_x(point_t &a, double x)
{
    a.x = x;
}
void set_point_y(point_t &a, double y)
{
    a.y = y;
}
void set_point_z(point_t &a, double z)
{
    a.z = z;
}
void set_point_n(point_t &a, int n)
{
    a.n = n;
}

void zero_point(point_t &a)
{
    a.n = 0;
    a.x = 0;
    a.y = 0;
    a.z = 0;
}

void set_point(point_t &a, double x, double y, double z, int n)
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


