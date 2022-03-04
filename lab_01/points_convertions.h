#ifndef POINTS_CONVERTIONS_H
#define POINTS_CONVERTIONS_H

#include "point.h"
#include "figure.h"


struct alpha_t
{
    double ax;
    double ay;
    double az;
};

struct data
{
    const char *filename;
    alpha_t rotation;
    struct
    {
        double k;
    } scale;
    struct
    {
        double dx;
        double dz;
        double dy;
    } move;
};

struct point &get_point(figure_t &fig, int i);
double get_alphax(alpha_t &d);
double get_alphay(alpha_t &d);
double get_alphaz(alpha_t &d);
double get_deltax(data &d);
double get_deltay(data &d);
double get_deltaz(data &d);
alpha_t get_alpha(data &d);
double get_k(data &d);
const char *get_filename(data &d);

#endif // POINTS_CONVERTIONS_H
