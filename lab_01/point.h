#ifndef POINT_H
#define POINT_H

struct point
{
    double x;
    double y;
    double z;
    int n;
};

double get_point_x(point a);
double get_point_y(point a);
double get_point_z(point a);
int get_point_n(point a);
void set_point_x(point &a, double x);
void set_point_y(point &a, double y);
void set_point_z(point &a, double z);
void set_point_n(point &a, int n);
void zero_point(point &a);

void set_point(point &a, double x, double y, double z, int n);
void copy_point(point &a, point &b);

#endif // POINT_H
