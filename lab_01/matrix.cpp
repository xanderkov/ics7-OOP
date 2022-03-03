#include "matrix.h"

void free_matrix(matrix_t mat, size_t n)
{
    if (!mat)
        return;
    for (size_t i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}


rc_type allocate_matrix(matrix_t &mat, size_t n)
{
    if (!n)
        return ERR_MEMORY;
    int **new_matrix = (int**)calloc(n, sizeof(int *));
    if (!new_matrix)
        return ERR_MEMORY;
    rc_type rc = OK;
    size_t i;
    for (i = 0; i < n && !rc; i++)
    {
        new_matrix[i] = (int *)calloc(n, sizeof(int));
        if (!new_matrix[i])
            rc = ERR_MEMORY;
    }
    if (rc)
        free_matrix(new_matrix, i);
    if (!rc)
        mat = new_matrix;
    return rc;
}
