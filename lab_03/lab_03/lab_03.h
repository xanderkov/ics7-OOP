#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab_03.h"

class lab_03 : public QMainWindow
{
    Q_OBJECT

public:
    lab_03(QWidget *parent = Q_NULLPTR);

private:
    Ui::lab_03Class ui;
};
