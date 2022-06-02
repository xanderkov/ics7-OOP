#ifndef LIFTCONTROLLER_H
#define LIFTCONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <memory>
#include <vector>

#include "define.h"
#include "button.h"

class LiftController : public QWidget
{
    Q_OBJECT

    enum LiftControllerState
    {
        FREE,
        BUSY
    };

public:
    explicit LiftController(QWidget *parent = nullptr);
    ~LiftController() = default;

signals:
    void new_target_signal(int floor);
    void stop_signal(bool f, int t = 1);

public slots:
    void new_target_slot(int floor);
    void pass_floor_slot(int floor, Direction dir);

private:
    int current_floor;
    int need_floor;

    LiftControllerState current_state;
    Direction control_direction;

    std::vector<std::shared_ptr<Button>> button_arr;
    std::vector<bool> visit_floor_arr;
    std::unique_ptr<QVBoxLayout> layout;

    bool be_target(int &new_floor_target);
};

#endif
