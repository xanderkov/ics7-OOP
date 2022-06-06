#include "../inc/liftcabin.h"
#include <iostream>

LiftCabin::LiftCabin(QObject *parent)
    : QObject{parent}
{
    this->current_state = FREE;

    QObject::connect(this, SIGNAL(door_open_signal()),
                     &door, SLOT(openning()));

    QObject::connect(&cabin_move_timer, SIGNAL(timeout()),
                     this, SLOT(liftcabin_target()));

    QObject::connect(&door, SIGNAL(closed_door_signal()),
                     this, SLOT(liftcabin_target()));
}

void LiftCabin::lifcabin_move()
{
    if (this->current_state != FREE)
        return;
    this->current_state = MOVE;
    cabin_move_timer.start(FLOOR_CROSS_TIME);
}

void LiftCabin::liftcabin_stop()
{
    this->current_state = WAIT;
    cabin_move_timer.stop();
    emit door_open_signal();
}

void LiftCabin::liftcabin_target()
{
    if (this->current_state != FREE)
    {
        this->current_state = FREE;
        emit pass_floor_signal(false);
    }
}
