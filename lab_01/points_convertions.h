#ifndef POINTS_CONVERTIONS_H
#define POINTS_CONVERTIONS_H

#include "point.h"

typedef struct data action_t;

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
    } scale ;
    struct
    {
        double dx;
        double dz;
        double dy;
    } move;
};

struct point &get_point(struct figure &fig, int i);
double get_alphax(alpha_t &d);
double get_alphay(alpha_t &d);
double get_alphaz(alpha_t &d);
double get_deltax(struct data &d);
double get_deltay(struct data &d);
double get_deltaz(struct data &d);
alpha_t get_alpha(action_t &d);
double get_k(struct data &d);
const char *get_filename(struct data &d);

#endif // POINTS_CONVERTIONS_H
