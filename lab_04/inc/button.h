#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QObject>

class Button : public QPushButton
{
    Q_OBJECT;

    enum ButtonState
    {
        ACTIVE,
        NOTACTIVE
    };

public:
    Button(QWidget *parent = nullptr);
    ~Button() = default;

    void set_floor(const int &floor);

signals:
    void press_signal(int floor);
    void unpress_signal();

public slots:
    void press();
    void unpress();

private:
    ButtonState current_state;

    int current_button_floor;
};

#endif // BUTTON_H
