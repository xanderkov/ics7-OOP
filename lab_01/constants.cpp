#include "constants.h"
#include <QMessageBox>

void print_warning(rc_type rc)
{
    if (rc == OK)
        return;
    QMessageBox mbox;
    switch (rc)
    {
        case ERR_OPEN_FILE:
            mbox.setText("При открытии файла произошла ошибка. Попробуйте еще раз. Попробуйте ввести полный путь к файлу");
        case ERR_INPUT:
            mbox.setText("Ошибка ввода");
        case ERR_MEMORY:
            mbox.setText("Возникла ошибка памяти");
        case ERR_PARAMETR:
            mbox.setText("Не верный параметры");
        default:
            mbox.setText("Неизвестная ошибка");
    }
    mbox.exec();
}
