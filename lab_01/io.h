#ifndef IO_H
#define IO_H

#include <stdlib.h>
#include <stdio.h>

#include "point.h"
#include "constants.h"
#include "figure.h"
#include "matrix.h"
#include "figure_conventions.h"

typedef FILE* file_adress;

rc_type open_file(file_adress &file, const char *filename);
void close_file(file_adress file);

void free_figure(struct figure &figure);
int read_from_file(struct figure &figure, file_adress file);

#endif // IO_H
