#include "../inc/lift.h"

Lift::Lift(QObject *parent)
    : QObject{parent}
{
    this->controller.setStyleSheet("background-color:blue;");

    QObject::connect(&cabin, SIGNAL(pass_floor_signal(bool, int)),
                     &controller, SLOT(new_target_slot(bool, int)));

    QObject::connect(&controller, SIGNAL(move_signal()),
                     &cabin, SLOT(lifcabin_move()));

    QObject::connect(&controller, SIGNAL(stop_signal()),
                     &cabin, SLOT(liftcabin_stop()));
}

QWidget *Lift::widget()
{
    return &this->controller;
}
