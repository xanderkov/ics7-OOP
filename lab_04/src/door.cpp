#include "../inc/door.h"
#include <iostream>

Door::Door()
    : current_state(CLOSED)
{
    QObject::connect(&open_timer, SIGNAL(timeout()),
                     this, SLOT(open()));

    QObject::connect(&wait_timer, SIGNAL(timeout()),
                     this, SLOT(closing()));

    QObject::connect(&close_timer, SIGNAL(timeout()),
                     this, SLOT(close()));
}


void Door::ready_to_move()
{
    if (current_state == CLOSED)
        emit closed_door_signal();
}

void Door::openning()
{
    if (current_state == CLOSED || current_state == CLOSING)
    {
        std::cout << "Двери открываются\n";

        if (this->current_state == CLOSED)
        {
            this->current_state = OPENNING;
            this->open_timer.start(DOOR_TIME);
        }
        else
        {
            this->current_state = OPENNING;
            auto timer = close_timer.remainingTime();

            close_timer.stop();
            this->open_timer.start(DOOR_TIME - timer);
        }
    }
}

void Door::open()
{
    if (current_state != OPENNING)
        return;
    this->current_state = OPENED;
    std::cout << "Двери открыты\n";
    this->wait_timer.start(DOOR_TIME);
}

void Door::closing()
{
    if (current_state != OPENED)
        return;
    this->current_state = CLOSING;
    std::cout << "Двери закрываются\n";
    this->close_timer.start(DOOR_TIME);
}

void Door::close()
{
    if (current_state != CLOSING)
        return;
    this->current_state = CLOSED;
    std::cout << "Двери закрыты\n";
    emit closed_door_signal();
}
