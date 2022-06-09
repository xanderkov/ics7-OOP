#include "../inc/liftcontroller.h"
#include <iostream>

LiftController::LiftController(QWidget *parent)
    : QWidget{parent}
{
    this->layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->setLayout(this->layout.get());
    this->current_floor = 1;
    this->control_direction = UP;
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
    Direction dir;
    if (got_new)
    {
        visit_floor_arr[floor - 1] = false;
        be_target(need_floor);
        dir = update_direction();
        if (dir == STAY)
            emit reach_floor_signal();
        else
            emit move_signal();
    }
    else if (be_target(need_floor))
    {
        dir = update_direction();

        if (dir != STAY)
        {
            emit move_signal();
            update_floor();
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
    Direction dir = update_direction();

    if (dir!= STAY)
        std::cout << "Лифт в пути на этаже № " << this->current_floor << "\n";
}

Direction LiftController::update_direction()
{
    Direction dir;
    if (this->need_floor < this->current_floor)
        dir = DOWN;
    else if (this->need_floor > this->current_floor)
        dir = UP;
    else
        dir = STAY;
    return dir;
}


bool LiftController::be_target(int &new_floor_target)
{
    int dir = DOWN;
    if (this->control_direction != STAY)
        dir = control_direction;

    for (int i = this->current_floor - 1; i >= 0 && i < ALL_FLOORS; i += dir)
        if (!this->visit_floor_arr[i])
        {
            this->control_direction = ((dir == UP) ? UP : DOWN);
            new_floor_target = i + 1;
            return true;
        }
    
    for (int i = this->current_floor - 1; i >= 0 && i < ALL_FLOORS; i -= dir)
        if (!this->visit_floor_arr[i])
        {
            this->control_direction = ((dir == UP) ? DOWN : UP);
            new_floor_target = i + 1;
            return true;
        }
    this->control_direction = STAY;

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