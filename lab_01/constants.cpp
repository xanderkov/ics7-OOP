#include "constants.h"
/*
#include "myscene.h"
#include "points_convertions.h"
#include "figure.h"
#include "io.h"
#include "figure_conventions.h"
*/

void print_warning(rc_type rc)
{
    if (rc == OK)
        return;
    QMessageBox mbox;
    switch (rc)
    {
        case ERR_OPEN_FILE:
            mbox.setText("При открытии файла произошла ошибка. Попробуйте еще раз. Попробуйте ввести полный путь к файлу");
        break;
        case ERR_INPUT:
            mbox.setText("Ошибка ввода");
            break;
        case ERR_MEMORY:
            mbox.setText("Возникла ошибка памяти");
            break;
        case ERR_PARAMETR:
            mbox.setText("Не верный параметр");
            break;
        default:
            QString text = QString::fromStdString(std::to_string(rc));
            mbox.setText(text);
            break;
    }
    mbox.exec();
}
