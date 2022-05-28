#ifndef __LAB_03_DISPLAY_H__
#define __LAB_03_DISPLAY_H__

#include <QtWidgets>
#include "../../implementation/commands/command.hpp"
#include "../../implementation/commands/camera/camera_command.hpp"
#include "../../implementation/commands/model/model_command.hpp"
#include "../../implementation/commands/scene/scene_command.hpp"
#include "../../implementation/drawer/drawer.hpp"
#include "../../implementation/facade/facade.hpp"

#include "../../implementation/exceptions/base_exception.hpp"
#include "../../implementation/commands/camera/move/move_camera.hpp"
#include "../../implementation/commands/model/move/move_model.hpp"
#include "../../implementation/commands/model/scale/scale_model.hpp"
#include "../../implementation/commands/model/rotate/rotate_model.hpp"

class Display : public QGraphicsView {
    Q_OBJECT
private:
    QWidget window;
    QPoint cursor;
    bool mouseLeftButtonPressed = false;
    bool mouseRightButtonPressed = false;

public:
    Display(QWidget* parent = nullptr) : QGraphicsView(parent) {
        qDebug() << this->parentWidget()->parentWidget();
    };

    void mousePressEvent(QMouseEvent* mouse) {
        qDebug() << "Mouse pressed";
        cursor = mouse->pos();
        qDebug() << "Cursor is" << cursor;

        if (mouse->button() == Qt::LeftButton)
            mouseLeftButtonPressed = true;

        if (mouse->button() == Qt::RightButton)
            mouseRightButtonPressed = true;

        mouse->accept();
    }

    void mouseReleaseEvent(QMouseEvent* mouse) {
        qDebug() << "Mouse released";
        mouseLeftButtonPressed = false;

        mouseRightButtonPressed = false;

        mouse->accept();
    }

    void mouseMoveEvent(QMouseEvent* mouse) {
        qDebug() << "Cursor was " << cursor;

        double dx = mouse->x() - cursor.x();
        double dy = mouse->y() - cursor.y();

        cursor = mouse->pos();

        qDebug() << "Cursor is " << cursor;

        if (mouseLeftButtonPressed) {
            emit moveSignal(dx, dy, 0);
        }

        if (mouseRightButtonPressed) {
            emit rotateSignal(dy, dx, 0);
        }

        mouse->accept();
    }

    ~Display() = default;
signals:
    void moveSignal(double x, double y, double z);

    void rotateSignal(double x, double y, double z);
};



#endif //__LAB_03_DISPLAY_H__
