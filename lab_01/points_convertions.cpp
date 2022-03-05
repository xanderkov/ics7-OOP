#include "points_convertions.h"
/*
#include "point.h"
#include "figure.h"
*/
struct point &get_point(figure_t &fig, const int i)
{
    return fig.arr[i];
}

double get_alphax(alpha_t &d)
{
    return d.ax;
}

double get_alphay(alpha_t &d)
{
    return d.ay;
}

double get_alphaz(alpha_t &d)
{
    return d.az;
}

alpha_t get_alpha(data &d)
{
    return d.rotation;
}

double get_deltax(data &d)
{
    return d.move.dx;
}

double get_deltay(data &d)
{
    return d.move.dy;
}

double get_deltaz(data &d)
{
    return d.move.dy;
}

double get_k(data &d)
{
    return d.scale.k;
}

const char *get_filename(data &d)
{
    return d.filename;
}
