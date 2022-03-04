#include "io.h"

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

rc_type read_line_point(file_adress file, point_t &p)
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

rc_type read_line_matrix(file_adress file, int &mi, int &mj)
{
    rc_type rc = ERR_INPUT;
    if (fscanf(file, "%d->%d", &mi, &mj) == 2)
        rc = OK;
    return rc;
}

rc_type allocate_array(point_t *&arr, size_t n)
{
    point_t *buf = new struct point[n];
    if (!buf)
        return ERR_MEMORY;
    arr = buf;
    return OK;
}

rc_type count_points(size_t &n, file_adress file)
{
    if (!file)
        return ERR_OPEN_FILE;
    struct point p;
    size_t num = 0;
    while (!(read_line_point(file, p)))
        num++;
    rewind_file(file);
    n = num;
    return OK;
}

rc_type create_array(point_t *arr, size_t n, file_adress file)
{
    if (!file || !n || !arr)
        return ERR_INPUT;
    struct point p;

    rc_type rc = OK;
    for (size_t i = 0; i < n && !rc; i++)
    {
        if (read_line_point(file, p) != OK)
            rc = ERR_INPUT;
        else
            copy_point(arr[i], p);
    }
    return rc;
}

rc_type create_matrix(matrix_t matrix, size_t n, file_adress file)
{
    if (!file || !n || !matrix)
        return ERR_INPUT;
    int mi, mj;
    while (read_line_matrix(file, mi, mj) == OK)
    {
        matrix[mi - 1][mj - 1] = 1;
        matrix[mj - 1][mi - 1] = 1;
    }
    return OK;
}


rc_type allocate_fig(figure_t &fig, size_t n)
{
    rc_type rc = allocate_array(fig.arr, n);
    if (rc) return rc;
    rc = allocate_matrix(fig.matrix, n);
    if (rc)
        free_fig(fig);
    return rc;
}

rc_type create_fig(figure_t &fig, size_t n, file_adress file)
{
    rc_type rc = OK;
    rc = create_array(fig.arr, n, file);
    if (!rc)
        rc = create_matrix(fig.matrix, n, file);
    return rc;
}

rc_type read_from_file(struct figure &fig, file_adress file)
{
    if (!file)
        return ERR_EMPTY;
    rc_type rc = OK;
    figure fig_copy = init_fig();
    rc = count_points(fig_copy.n, file);
    if (rc)
        return rc;
    rc = allocate_fig(fig_copy, fig_copy.n);
    if (rc)
        return rc;
    rc = create_fig(fig_copy, fig_copy.n, file);
    if (rc == OK)
    {
        free_fig(fig);
        copy_fig(fig, fig_copy);
    }
    else
        free_fig(fig);
    return rc;
}
