#ifndef DEFINE_H
#define DEFINE_H

#include <QTimer>
#include <QTextEdit>

enum Direction
{
    DOWN = -1,
    STAY = 0,
    UP = 1
};

#define START_FLOOR 1
#define ALL_FLOORS 13
#define FLOOR_CROSS_TIME 1000
#define LIFT_WAIT_TIME 1000
#define DOOR_TIME 1000

#endif // DEFINE_H
