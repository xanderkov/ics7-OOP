#include "io.h"
/*
#include "point.h"
#include "constants.h"
#include "figure.h"
#include "matrix.h"
#include "figure_conventions.h"
*/


rc_type open_file(file_adress &f, const char *filename)
{
    file_adress file = fopen(filename, "r");
    if (!file)
        return ERR_OPEN_FILE;
    f = file;
    return OK;
}

void close_file(file_adress file)
{
    fclose(file);
}

void rewind_file(file_adress file)
{
    rewind(file);
}

rc_type read_line_point(point &p, file_adress file)
{
    int n;
    double x, y, z;
    rc_type rc = ERR_INPUT;
    if (fscanf(file, "%d%lf%lf%lf", &n, &x, &y, &z) == 4)
    {
        set_point(p, x, y, z, n);
        rc = OK;
    }
    return rc;
}

rc_type read_line_matrix(int &mi, int &mj, file_adress file)
{
    rc_type rc = ERR_INPUT;
    if (fscanf(file, "%d->%d", &mi, &mj) == 2)
        rc = OK;
    return rc;
}

rc_type allocate_array(point *&arr, size_t n)
{
    point *buf = new point[n];
    if (!buf)
        return ERR_MEMORY;
    arr = buf;
    return OK;
}


rc_type check_points(int n, file_adress file)
{
    rc_type rc = OK;
    int mi, mj;
    while ((read_line_matrix(mi, mj, file)) == OK && rc == OK)
        if (mi <= n && mj <= n)
            rc = ERR_INPUT;
    return rc;
}


rc_type count_points(figure_t *fig, file_adress file)
{
    if (!file)
        return ERR_OPEN_FILE;
    point p;
    int num = 0;
    while (!(read_line_point(p, file)))
        num++;
    rc_type rc = check_points(num, file);
    if (!rc)
        set_fig_n(*fig, num);
    return rc;
}


rc_type read_array(point *arr, const size_t n, file_adress file)
{
    if (!file || !n || !arr)
        return ERR_INPUT;
    point p;
    rc_type rc = OK;
    for (size_t i = 0; i < n && !rc; i++)
    {
        if (read_line_point(p, file))
            rc = ERR_INPUT;
        else
            copy_point(arr[i], p);
    }
    return rc;
}

rc_type read_matrix(matrix_t &matrix, const size_t n, file_adress file)
{
    if (!file || !n || !matrix)
        return ERR_INPUT;
    int mi, mj;
    while (read_line_matrix(mi, mj, file) == OK)
    {
        matrix[mi - 1][mj - 1] = 1;
        matrix[mj - 1][mi - 1] = 1;
    }
    return OK;
}


rc_type allocate_fig(figure_t &fig)
{

    const size_t n = get_fig_n(fig);
    rc_type rc = allocate_array(fig.arr, n);
    if (rc) return rc;
    rc = allocate_matrix(fig.matrix, n);
    if (rc)
        free_fig(fig);
    return rc;
}

rc_type create_fig(figure_t &fig, file_adress file)
{
    rewind_file(file);
    const size_t n = get_fig_n(fig);
    rc_type rc = OK;
    rc = read_array(fig.arr, n, file);
    if (!rc)
        rc = read_matrix(fig.matrix, n, file);
    return rc;
}

rc_type read_from_file(figure_t &fig, file_adress file)
{
    if (!file)
        return ERR_EMPTY;
    rc_type rc = OK;
    figure_t fig_copy = init_fig();
    rc = count_points(&fig_copy, file);
    if (!rc)
    {
        rc = allocate_fig(fig_copy);
        if (!rc)
        {
            rc = create_fig(fig_copy, file);
            if (!rc)
            {
                free_fig(fig);
                copy_fig(fig, fig_copy);
            }
        }
    }
    return rc;
}
