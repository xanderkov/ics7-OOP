#include "lift.h"

Lift::Lift(QObject *parent)
    : QObject{parent}
{
    this->controller.setStyleSheet("background-color:blue;");

    QObject::connect(&cabin, SIGNAL(pass_floor_signal(int,Direction)),
                     &controller, SLOT(pass_floor_slot(int,Direction)));

    QObject::connect(&controller, SIGNAL(new_target_signal(int)),
                     &cabin, SLOT(liftcabin_target(int)));

    QObject::connect(&controller, SIGNAL(stop_signal(bool,int)),
                     &cabin, SLOT(liftcabin_stop(bool,int)));
}

QWidget *Lift::widget()
{
    return &this->controller;
}
