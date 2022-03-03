#ifndef CONTROLLER_H
#define CONTROLLER_H

#define ROTATE 3
#define SCALE 2
#define MOVE 1
#define DOWNLOAD 4
#define DELETE 5
#define DRAW 6

#include"myscene.h"
#include"points_convertions.h"
#include"figure.h"


rc_type controller(myscene_t scene, int act_number, action_t act);


#endif // CONTROLLER_H
