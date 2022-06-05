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
    void pass_floor_signal(bool, int = 1);

public slots:
    void lifcabin_move();
    void liftcabin_target();
    void liftcabin_stop();

private:

    Door door;
    LiftCabinState current_state;

    QTimer cabin_move_timer;

};

#endif // LIFTCABIN_H
