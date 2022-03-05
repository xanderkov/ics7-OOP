#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

typedef int** matrix_t;

void free_matrix(matrix_t mat, const size_t n);
rc_type allocate_matrix(matrix_t &matrix, const size_t n);


#endif // MATRIX_H
