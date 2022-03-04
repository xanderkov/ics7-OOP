#ifndef CONTROLLER_H
#define CONTROLLER_H

#define ROTATE 3
#define SCALE 2
#define MOVE 1
#define DOWNLOAD 4
#define DELETE_NUM 5
#define DRAW 6

#include "myscene.h"
#include "points_convertions.h"
#include "figure.h"
#include "io.h"
#include "figure_conventions.h"


rc_type controller(myscene_t scene, int act_number, data act);


#endif // CONTROLLER_H
