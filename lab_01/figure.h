#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"
#include "matrix.h"

typedef struct figure figure_t;

struct figure
{
    struct point *arr;
    size_t n;
    int **matrix;
};

size_t &get_fig_n(struct figure &fig);
int is_empty(struct figure &fig);
void free_fig(struct figure &fig);
figure_t init_figure();
int get_matrix_el(figure_t fig, size_t i, size_t j);
void set_fig_n(figure_t &fig, size_t n);
void set_fig_arr(figure_t &fig, point_t *arr);
void set_fig_matrix(figure_t &fig, matrix_t mt);
void copy_figure(figure_t &fig, figure_t &work);

#endif // FIGURE_H
