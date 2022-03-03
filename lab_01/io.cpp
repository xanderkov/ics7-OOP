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
        if (read_line_point(file, p))
            rc = ERR_INPUT;
        else
            copy_point(arr[i], p);
    }
}

rc_type create_matrix(matrix_t matrix, size_t n, file_adress file)
{
    if (!file || !n || !matrix)
        return ERR_INPUT;
    int mi, mj;
    while (!(read_line_matrix(file, mi, mj)))
    {
        matrix[mi - 1][mj - 1] = 1;
        matrix[mj - 1][mi - 1] = 1;
    }
    return OK;
}

void free_figure(struct figure &figure);

rc_type allocate_figure(figure_t &figure, size_t n)
{
    rc_type rc = allocate_array(figure.arr, n);
    if (rc) return rc;
    rc = allocate_matrix(figure.matrix, n);
    if (rc)
        free_figure(figure);
    return rc;
}

rc_type create_figure(figure_t &figure, size_t n, file_adress file)
{
    rc_type rc = OK;
    rc = create_array(figure.arr, n, file);
    if (!rc)
        rc = create_matrix(figure.matrix, n, file);
    return rc;
}

rc_type read_from_file(struct figure &fig, file_adress file)
{
    if (!file)
        return ERR_EMPTY;
    rc_type rc = OK;
    figure figure = init_figure();
    rc = count_points(figure.n, file);
    if (rc)
        return rc;
    rc = allocate_figure(figure, figure.n);
    if (rc)
        return rc;
    rc = create_figure(figure, figure.n, file);
    if (!rc)
    {
        free_figure(figure);
        copy_figure(figure, fig);
    }
    else
        free_figure(fig);
}
