#ifndef FIGURE_CONVENTIONS_H
#define FIGURE_CONVENTIONS_H

#include "io.h"
#include "mainwindow.h"
#include "point.h"
#include "math.h"
#include "figure.h"
#include "points_convertions.h"

rc_type download_model(figure_t &fig, data act);
rc_type move_fig(figure_t &fig, data act);
rc_type rotation_fig(figure_t &fig, data act);
rc_type scale_fig(figure_t &fig, data act);
void clear_fig(figure_t &fig);
void draw_fig(figure_t &fig, myscene_t scene);
void move(point &a, const double dx, const double dy, const double dz);
void scale(point &a, const double k, point m);
void rotation(point &a, point c, alpha_t alpha);

void draw_model(figure_t fig, myscene_t scene);

#endif // FIGURE_CONVENTIONS_H
