#ifndef LIFT_H
#define LIFT_H
#include <QObject>
#include "liftcabin.h"
#include "liftcontroller.h"

class Lift : public QObject
{
    Q_OBJECT
public:
    explicit Lift(QObject *parent = nullptr);
    ~Lift() = default;
    QWidget *widget();

private:
    LiftController controller;
    LiftCabin cabin;

};

#endif // LIFT_H
