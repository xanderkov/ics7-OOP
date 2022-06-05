#include "../inc/liftcontroller.h"
#include <iostream>

LiftController::LiftController(QWidget *parent)
    : QWidget{parent}
{
    this->layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->setLayout(this->layout.get());
    this->current_floor = 1;
    for (int i = 0; i < ALL_FLOORS; ++i)
    {
        std::shared_ptr<Button> new_button(new Button);
        new_button->set_floor(ALL_FLOORS - i);
        new_button->setText(QString::number(ALL_FLOORS - i));

        this->button_arr.insert(this->button_arr.begin(), new_button);

        layout->addWidget(dynamic_cast<QPushButton*>(new_button.get()));

        this->visit_floor_arr.push_back(true);

        QObject::connect(new_button.get(), SIGNAL(press_signal(bool, int)),
                         this, SLOT(new_target_slot(bool, int)));
    }
    QObject::connect(this, SIGNAL(reach_floor_signal()), this, SLOT(reach_floor()));
}

void LiftController::new_target_slot(bool got_new, int floor)
{
    this->current_state = BUSY;

    if (got_new)
    {
        visit_floor_arr[floor - 1] = false;
        be_target(need_floor);
        //std::cout << "Лифт получил цель этаж № " << this->need_floor << "\n";
        update_direction();
        if (control_direction == STAY)
            emit reach_floor_signal();
        else
            emit move_signal();
    }
    else if (be_target(need_floor))
    {
        update_direction();

        if (control_direction != STAY)
        {
            current_floor += control_direction;
            std::cout << "Лифт в пути на этаже № " << this->current_floor << "\n";
            emit move_signal();
        }
        else
        {
            emit reach_floor_signal();
        }
    }
}

void LiftController::update_floor()
{
    this->current_floor += this->control_direction;
    update_direction();

    if (this->control_direction != STAY)
        std::cout << "Лифт в пути на этаже № " << this->current_floor << "\n";
}

void LiftController::update_direction()
{
    if (this->need_floor < this->current_floor)
        this->control_direction = DOWN;
    else if (this->need_floor > this->current_floor)
        this->control_direction = UP;
    else
        this->control_direction = STAY;
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
    
    for (int i = this->current_floor - 1; i >= 0 && i < ALL_FLOORS; i -= dir)
        if (!this->visit_floor_arr[i])
        {
            new_floor_target = i + 1;
            return true;
        }

    return false;
}


void LiftController::reach_floor()
{
    if (this->current_state != BUSY) return;

    current_state = FREE;

    std::cout << "Лифт приехал на этаж № " << this->current_floor << "\n";

    visit_floor_arr[need_floor - 1] = true;
    emit this->button_arr[current_floor - 1]->unpress_signal();
    be_target(need_floor);

    emit stop_signal();
}