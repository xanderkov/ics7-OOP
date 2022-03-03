#ifndef FIGURE_CONVENTIONS_H
#define FIGURE_CONVENTIONS_H

#include "io.h"
#include "mainwindow.h"
#include "point.h"
#include "math.h"
#include "figure.h"
#include "points_convertions.h"

rc_type download_model(figure_t &fig, action_t act);
rc_type move_fig(figure_t &fig, action_t act);
rc_type rotation_fig(figure_t &fig, action_t act);
rc_type scale_fig(figure_t &fig, action_t act);
void clear_fig(figure_t &fig);
void draw_fig(figure_t &fig, myscene_t scene);
void move(struct point &a, double dx, double dy, double dz);
void scale(struct point &a, struct point m, double k);
void rotation(struct point &a, struct point c, double ax, double ay, double az);

void draw_model(figure_t fig, myscene_t scene);

#endif // FIGURE_CONVENTIONS_H
