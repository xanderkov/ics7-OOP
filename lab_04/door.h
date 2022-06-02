#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include "define.h"

class Door : public QObject
{
    Q_OBJECT
    enum DoorState
    {
        OPENED,
        OPENNING,
        CLOSING,
        CLOSED
    };

public:
    Door();
    ~Door() = default;

signals:
    void closed_door_signal();

private slots:
    void openning();
    void closing();


public slots:
    void open();
    void close();
    void ready_to_move();

private:
    DoorState current_state;

    QTimer open_timer;
    QTimer close_timer;
    QTimer wait_timer;
};

#endif // DOOR_H
