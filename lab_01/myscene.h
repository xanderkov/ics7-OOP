#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include "constants.h"
#include "point.h"
#include "math.h"

struct myscene_t
{
    QGraphicsScene *scene;
};


void draw_line_scene(myscene_t scene, point p1, point p2);
void draw_point_scene(myscene_t scene, point p1);
void clear_scene(myscene_t scene);

#endif // MYSCENE_H
