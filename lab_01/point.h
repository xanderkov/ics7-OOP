#ifndef POINT_H
#define POINT_H

typedef struct point point_t;

struct point
{
    double x;
    double y;
    double z;
    int n;
};

double get_point_x(point_t a);
double get_point_y(point_t a);
double get_point_z(point_t a);
int get_point_n(point_t a);
void set_point_x(point_t &a, double x);
void set_point_y(point_t &a, double y);
void set_point_z(point_t &a, double z);
void set_point_n(point_t &a, int n);
void zero_point(point_t &a);

void set_point(point_t &a, double x, double y, double z, int n);
void copy_point(point &a, point &b);

#endif // POINT_H
