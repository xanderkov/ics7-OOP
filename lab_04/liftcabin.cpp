#include "liftcabin.h"
#include <iostream>

LiftCabin::LiftCabin(QObject *parent)
    : QObject{parent}
{
    this->current_state = FREE;
    this->current_floor = 1;
    this->need_floor = 1;
    this->cabin_direction = STAY;

    QObject::connect(this, SIGNAL(move_signal()),
                     &door, SLOT(ready_to_move()));

    QObject::connect(this, SIGNAL(stop_signal(bool, int)),
                     this, SLOT(liftcabin_stop(bool,int)));

    QObject::connect(this, SIGNAL(door_open_signal()),
                     &door, SLOT(openning()));

    QObject::connect(&cabin_move_timer, SIGNAL(timeout()),
                     this, SLOT(lifcabin_move()));

    QObject::connect(&door, SIGNAL(closed_door_signal()),
                     this, SLOT(lifcabin_move()));
}

void LiftCabin::lifcabin_move()
{
    if (current_state == MOVE || current_state == WAIT)
    {
        this->current_state = MOVE;
        cabin_move_timer.start(FLOOR_CROSS_TIME);

        std::cout << "Лифт в пути на этаже № " << this->current_floor << "\n";
        emit pass_floor_signal(current_floor, this->cabin_direction);

        if (current_floor == need_floor)
            return;
        if (current_floor > need_floor)
        {
            this->cabin_direction = DOWN;
            this->current_floor = current_floor - 1;
        }
        else
        {
            this->cabin_direction = UP;
            this->current_floor = current_floor + 1;
        }
    }
}

void LiftCabin::liftcabin_stop(bool last, int floor)
{
    if (last)
        this->current_state = FREE;
    else
    {
        this->current_state = WAIT;
        this->need_floor = floor;
    }

    this->cabin_move_timer.stop();
    emit door_open_signal();
}

void LiftCabin::liftcabin_target(int floor)
{
    if (current_state == FREE)
    {
        this->current_state = WAIT;
        this->need_floor = floor;

        if (this->current_floor == this->need_floor)
            emit pass_floor_signal(current_floor, this->cabin_direction);
        else
        {
            if (need_floor > current_floor)
                this->cabin_direction = UP;
            else
                this->cabin_direction = DOWN;
            emit move_signal();
        }
    }
}
