#include "figure.h"

size_t &get_fig_n(struct figure &fig)
{
    return fig.n;
}


int is_empty(struct figure &fig)
{
    return !(fig.arr && fig.matrix && get_fig_n(fig));
}


void free_fig(struct figure &fig)
{
    if (fig.arr)
        delete [] fig.arr;
    if (fig.matrix)
        free_matrix(fig.matrix, fig.n);

    fig.n = 0;
    fig.matrix = NULL;
    fig.arr = NULL;
}


figure_t init_fig()
{
    figure_t fig;
    fig.n = 0;
    fig.matrix = NULL;
    fig.arr = NULL;
    return fig;
}


int get_matrix_el(figure_t fig, size_t i, size_t j)
{
    return fig.matrix[i][j];
}

void set_fig_matrix(figure_t &fig, matrix_t mt)
{
    fig.matrix = mt;
}
void set_fig_arr(figure_t &fig, point_t *arr)
{
    fig.arr = arr;
}
void set_fig_n(figure_t &fig, size_t n)
{
    fig.n = n;
}


void copy_fig(figure_t &fig, figure_t &work)
{
    fig.n = work.n;
    fig.arr = work.arr;
    fig.matrix = work.matrix;
}
