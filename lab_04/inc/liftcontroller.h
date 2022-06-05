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
    void reach_floor_signal();
    void stop_signal();
    void move_signal();

public slots:
    void reach_floor();
    void new_target_slot(bool got_new, int floor);

private:
    int current_floor;
    int need_floor;

    LiftControllerState current_state;
    Direction control_direction;

    std::vector<std::shared_ptr<Button>> button_arr;
    std::vector<bool> visit_floor_arr;
    std::unique_ptr<QVBoxLayout> layout;

    bool be_target(int &new_floor_target);

    void update_direction();
    void update_floor();
    
};

#endif
