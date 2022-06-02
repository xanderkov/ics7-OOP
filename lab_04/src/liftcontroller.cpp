#include "../inc/liftcontroller.h"
#include <iostream>

LiftController::LiftController(QWidget *parent)
    : QWidget{parent}
{
    this->layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->setLayout(this->layout.get());

    for (int i = 0; i < ALL_FLOORS; ++i)
    {
        std::shared_ptr<Button> new_button(new Button);
        new_button->set_floor(ALL_FLOORS - i);
        new_button->setText(QString::number(ALL_FLOORS - i));

        this->button_arr.insert(this->button_arr.begin(), new_button);

        layout->addWidget(dynamic_cast<QPushButton*>(new_button.get()));

        this->visit_floor_arr.push_back(true);

        QObject::connect(new_button.get(), SIGNAL(press_signal(int)),
                         this, SLOT(new_target_slot(int)));
    }
}

void LiftController::new_target_slot(int floor)
{
    this->current_state = BUSY;
    this->visit_floor_arr[floor - 1] = false;

    be_target(floor);

    this->need_floor = floor;
    emit new_target_signal(floor);
}

void LiftController::pass_floor_slot(int floor, Direction dir)
{
    if (this->current_state != BUSY)
        return;
    this->current_floor = floor;
    this->control_direction = dir;

    if (current_floor != need_floor)
        return;
    if (this->current_state != BUSY)
        return;

    this->current_floor = floor;
    this->control_direction = dir;

    if (current_floor != need_floor)
        return;

    std::cout << "Лифт приехал на этаж № " << floor << "\n";

    emit this->button_arr[floor - 1]->unpress_signal();
    this->visit_floor_arr[floor - 1] = true;

    if (be_target(floor))
    {
        this->need_floor = floor;
        emit stop_signal(false, floor);
    }
    else
    {
        this->current_state = FREE;
        emit stop_signal(true);
    }
}

bool LiftController::be_target(int &new_floor_target)
{
    int dir;
    if (this->control_direction != STAY)
        dir = control_direction;
    else
        dir = DOWN;

    for (int i = this->current_floor - 1; i >= 0 && i < ALL_FLOORS; i += dir)
        if (!this->visit_floor_arr[i])
        {
            new_floor_target = i + 1;
            return true;
        }

    return false;
}
