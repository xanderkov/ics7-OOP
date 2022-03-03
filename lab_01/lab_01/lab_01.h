#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab_01.h"

class lab_01 : public QMainWindow
{
    Q_OBJECT

public:
    lab_01(QWidget *parent = Q_NULLPTR);

private:
    Ui::lab_01Class ui;
};
