#ifndef LIFTCABIN_H
#define LIFTCABIN_H

#include <QObject>
#include "door.h"
#include "liftcontroller.h"

class LiftCabin : public QObject
{
    Q_OBJECT

    enum LiftCabinState
    {
        WAIT,
        FREE,
        MOVE
    };

public:
    explicit LiftCabin(QObject *parent = nullptr);
    ~LiftCabin() = default;

signals:
    void door_open_signal();
    void pass_floor_signal(int floor, Direction dir);
    void move_signal();
    void stop_signal(bool = true, int = 1);

public slots:
    void lifcabin_move();
    void liftcabin_target(int floor);
    void liftcabin_stop(bool last, int floor = 1);

private:
    int current_floor;
    int need_floor;

    Door door;
    Direction cabin_direction;
    LiftCabinState current_state;

    QTimer cabin_move_timer;

};

#endif // LIFTCABIN_H
