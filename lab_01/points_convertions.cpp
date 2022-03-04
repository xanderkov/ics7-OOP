#include "points_convertions.h"

struct point &get_point(struct figure &fig, int i)
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

alpha_t get_alpha(action_t &d)
{
    return d.rotation;
}

double get_deltax(struct data &d)
{
    return d.move.dx;
}

double get_deltay(struct data &d)
{
    return d.move.dy;
}

double get_deltaz(struct data &d)
{
    return d.move.dy;
}

double get_k(struct data &d)
{
    return d.scale.k;
}

const char *get_filename(struct data &d)
{
    return d.filename;
}
