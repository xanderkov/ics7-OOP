/********************************************************************************
** Form generated from reading UI file 'designWODTxs.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGNWODTXS_H
#define DESIGNWODTXS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "display.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *up_btn;
    QPushButton *left_btn;
    QPushButton *load_camera_btn;
    QPushButton *right_btn;
    QPushButton *add_camera_btn;
    QPushButton *load_model_btn;
    QFrame *frame_4;
    QFrame *move_label;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *dy_box;
    QDoubleSpinBox *dx_box;
    QDoubleSpinBox *dz_box;
    QPushButton *move_btn;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QLabel *label_5;
    QLabel *label_4;
    QDoubleSpinBox *ky_box;
    QDoubleSpinBox *kx_box;
    QLabel *label_6;
    QDoubleSpinBox *kz_box;
    QPushButton *scale_btn;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QLabel *label_12;
    QDoubleSpinBox *ay_box;
    QDoubleSpinBox *ax_box;
    QDoubleSpinBox *az_box;
    QLabel *label_10;
    QPushButton *rotate_btn;
    QLabel *label_11;
    QPushButton *down_btn;
    Display *display;
    QPushButton *change_model_btn;
    QLabel *label_9;
    QLabel *curr_model_lbl;
    QPushButton *change_camera_btn;
    QLabel *label_8;
    QLabel *curr_camera_lbl;
    QListWidget *objects_list;
    QPushButton *remove_object_btn;
    QPushButton *clear_scene_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1308, 508);
        QPalette palette;
        QBrush brush(QColor(114, 159, 207, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(220, 222, 218, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(93, 94, 91, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(124, 126, 121, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        QBrush brush4(QColor(186, 189, 182, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        up_btn = new QPushButton(centralwidget);
        up_btn->setObjectName(QString::fromUtf8("up_btn"));
        up_btn->setGeometry(QRect(1040, 360, 80, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        up_btn->setFont(font);
        left_btn = new QPushButton(centralwidget);
        left_btn->setObjectName(QString::fromUtf8("left_btn"));
        left_btn->setGeometry(QRect(950, 390, 80, 23));
        left_btn->setFont(font);
        load_camera_btn = new QPushButton(centralwidget);
        load_camera_btn->setObjectName(QString::fromUtf8("load_camera_btn"));
        load_camera_btn->setGeometry(QRect(950, 130, 201, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(10);
        load_camera_btn->setFont(font1);
        right_btn = new QPushButton(centralwidget);
        right_btn->setObjectName(QString::fromUtf8("right_btn"));
        right_btn->setGeometry(QRect(1130, 390, 80, 23));
        right_btn->setFont(font);
        add_camera_btn = new QPushButton(centralwidget);
        add_camera_btn->setObjectName(QString::fromUtf8("add_camera_btn"));
        add_camera_btn->setGeometry(QRect(950, 160, 201, 24));
        add_camera_btn->setFont(font1);
        load_model_btn = new QPushButton(centralwidget);
        load_model_btn->setObjectName(QString::fromUtf8("load_model_btn"));
        load_model_btn->setGeometry(QRect(950, 100, 201, 24));
        load_model_btn->setFont(font1);
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(710, 10, 221, 461));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFont(font);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        move_label = new QFrame(frame_4);
        move_label->setObjectName(QString::fromUtf8("move_label"));
        move_label->setGeometry(QRect(10, 10, 206, 141));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(move_label->sizePolicy().hasHeightForWidth());
        move_label->setSizePolicy(sizePolicy1);
        move_label->setFont(font);
        move_label->setFrameShape(QFrame::StyledPanel);
        move_label->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(move_label);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        dy_box = new QDoubleSpinBox(move_label);
        dy_box->setObjectName(QString::fromUtf8("dy_box"));

        gridLayout_5->addWidget(dy_box, 4, 0, 1, 1);

        dx_box = new QDoubleSpinBox(move_label);
        dx_box->setObjectName(QString::fromUtf8("dx_box"));

        gridLayout_5->addWidget(dx_box, 5, 0, 1, 1);

        dz_box = new QDoubleSpinBox(move_label);
        dz_box->setObjectName(QString::fromUtf8("dz_box"));

        gridLayout_5->addWidget(dz_box, 3, 0, 1, 1);

        move_btn = new QPushButton(move_label);
        move_btn->setObjectName(QString::fromUtf8("move_btn"));
        move_btn->setFont(font);

        gridLayout_5->addWidget(move_btn, 6, 0, 1, 1);

        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 157, 205, 141));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFont(font);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        label_5->setFont(font2);

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        ky_box = new QDoubleSpinBox(frame_2);
        ky_box->setObjectName(QString::fromUtf8("ky_box"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(11);
        ky_box->setFont(font3);
        ky_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        ky_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ky_box->setMinimum(0.000000000000000);
        ky_box->setMaximum(10000000000000000000000.000000000000000);
        ky_box->setValue(1.000000000000000);

        gridLayout_6->addWidget(ky_box, 1, 1, 1, 1);

        kx_box = new QDoubleSpinBox(frame_2);
        kx_box->setObjectName(QString::fromUtf8("kx_box"));
        kx_box->setFont(font3);
        kx_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        kx_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kx_box->setMinimum(0.000000000000000);
        kx_box->setMaximum(10000000000000000.000000000000000);
        kx_box->setValue(1.000000000000000);

        gridLayout_6->addWidget(kx_box, 0, 1, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        gridLayout_6->addWidget(label_6, 2, 0, 1, 1);

        kz_box = new QDoubleSpinBox(frame_2);
        kz_box->setObjectName(QString::fromUtf8("kz_box"));
        kz_box->setFont(font3);
        kz_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        kz_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kz_box->setMinimum(0.000000000000000);
        kz_box->setMaximum(10000000000000000.000000000000000);
        kz_box->setValue(1.000000000000000);

        gridLayout_6->addWidget(kz_box, 2, 1, 1, 1);

        scale_btn = new QPushButton(frame_2);
        scale_btn->setObjectName(QString::fromUtf8("scale_btn"));
        scale_btn->setFont(font);

        gridLayout_6->addWidget(scale_btn, 3, 0, 1, 2);

        frame_3 = new QFrame(frame_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 304, 202, 141));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy2);
        frame_3->setFont(font);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);

        gridLayout_7->addWidget(label_12, 1, 0, 1, 1);

        ay_box = new QDoubleSpinBox(frame_3);
        ay_box->setObjectName(QString::fromUtf8("ay_box"));
        ay_box->setFont(font3);
        ay_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        ay_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ay_box->setMinimum(-10000000000000000000000.000000000000000);
        ay_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_7->addWidget(ay_box, 1, 1, 1, 1);

        ax_box = new QDoubleSpinBox(frame_3);
        ax_box->setObjectName(QString::fromUtf8("ax_box"));
        ax_box->setFont(font3);
        ax_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        ax_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ax_box->setMinimum(-10000000000000000.000000000000000);
        ax_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_7->addWidget(ax_box, 0, 1, 1, 1);

        az_box = new QDoubleSpinBox(frame_3);
        az_box->setObjectName(QString::fromUtf8("az_box"));
        az_box->setFont(font3);
        az_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        az_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        az_box->setMinimum(-99999999999999991611392.000000000000000);
        az_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_7->addWidget(az_box, 2, 1, 1, 1);

        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);

        gridLayout_7->addWidget(label_10, 2, 0, 1, 1);

        rotate_btn = new QPushButton(frame_3);
        rotate_btn->setObjectName(QString::fromUtf8("rotate_btn"));
        rotate_btn->setFont(font);

        gridLayout_7->addWidget(rotate_btn, 3, 0, 1, 2);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);

        gridLayout_7->addWidget(label_11, 0, 0, 1, 1);

        down_btn = new QPushButton(centralwidget);
        down_btn->setObjectName(QString::fromUtf8("down_btn"));
        down_btn->setGeometry(QRect(1040, 420, 80, 23));
        down_btn->setFont(font);
        display = new Display(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(10, 10, 691, 461));
        display->setFont(font);
        change_model_btn = new QPushButton(centralwidget);
        change_model_btn->setObjectName(QString::fromUtf8("change_model_btn"));
        change_model_btn->setGeometry(QRect(1220, 270, 71, 21));
        change_model_btn->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(950, 260, 101, 41));
        label_9->setFont(font3);
        label_9->setAlignment(Qt::AlignCenter);
        curr_model_lbl = new QLabel(centralwidget);
        curr_model_lbl->setObjectName(QString::fromUtf8("curr_model_lbl"));
        curr_model_lbl->setGeometry(QRect(1080, 270, 131, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        curr_model_lbl->setFont(font4);
        curr_model_lbl->setAlignment(Qt::AlignCenter);
        change_camera_btn = new QPushButton(centralwidget);
        change_camera_btn->setObjectName(QString::fromUtf8("change_camera_btn"));
        change_camera_btn->setGeometry(QRect(1220, 210, 71, 22));
        change_camera_btn->setFont(font);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(950, 200, 117, 46));
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignCenter);
        curr_camera_lbl = new QLabel(centralwidget);
        curr_camera_lbl->setObjectName(QString::fromUtf8("curr_camera_lbl"));
        curr_camera_lbl->setGeometry(QRect(1068, 200, 151, 46));
        curr_camera_lbl->setFont(font4);
        curr_camera_lbl->setAlignment(Qt::AlignCenter);
        objects_list = new QListWidget(centralwidget);
        objects_list->setObjectName(QString::fromUtf8("objects_list"));
        objects_list->setGeometry(QRect(950, 20, 200, 70));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(objects_list->sizePolicy().hasHeightForWidth());
        objects_list->setSizePolicy(sizePolicy3);
        objects_list->setMaximumSize(QSize(200, 300));
        remove_object_btn = new QPushButton(centralwidget);
        remove_object_btn->setObjectName(QString::fromUtf8("remove_object_btn"));
        remove_object_btn->setGeometry(QRect(1160, 70, 101, 22));
        remove_object_btn->setFont(font);
        clear_scene_btn = new QPushButton(centralwidget);
        clear_scene_btn->setObjectName(QString::fromUtf8("clear_scene_btn"));
        clear_scene_btn->setGeometry(QRect(1160, 20, 101, 22));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(clear_scene_btn->sizePolicy().hasHeightForWidth());
        clear_scene_btn->setSizePolicy(sizePolicy4);
        clear_scene_btn->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(kx_box, ky_box);
        QWidget::setTabOrder(ky_box, kz_box);
        QWidget::setTabOrder(kz_box, scale_btn);
        QWidget::setTabOrder(scale_btn, ax_box);
        QWidget::setTabOrder(ax_box, ay_box);
        QWidget::setTabOrder(ay_box, az_box);
        QWidget::setTabOrder(az_box, rotate_btn);
        QWidget::setTabOrder(rotate_btn, left_btn);
        QWidget::setTabOrder(left_btn, up_btn);
        QWidget::setTabOrder(up_btn, load_model_btn);
        QWidget::setTabOrder(load_model_btn, add_camera_btn);
        QWidget::setTabOrder(add_camera_btn, down_btn);
        QWidget::setTabOrder(down_btn, right_btn);

        retranslateUi(MainWindow);

        objects_list->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lab 03", nullptr));
        up_btn->setText(QCoreApplication::translate("MainWindow", "\342\254\206", nullptr));
        left_btn->setText(QCoreApplication::translate("MainWindow", "\342\227\200", nullptr));
        load_camera_btn->setText(QCoreApplication::translate("MainWindow", "Load camera", nullptr));
        right_btn->setText(QCoreApplication::translate("MainWindow", "\342\226\266", nullptr));
        add_camera_btn->setText(QCoreApplication::translate("MainWindow", "Add Camera", nullptr));
        load_model_btn->setText(QCoreApplication::translate("MainWindow", "Load model", nullptr));
        dy_box->setPrefix(QCoreApplication::translate("MainWindow", "dy: ", nullptr));
        dx_box->setPrefix(QCoreApplication::translate("MainWindow", "dx: ", nullptr));
        dz_box->setPrefix(QCoreApplication::translate("MainWindow", "dz: ", nullptr));
        move_btn->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " ky", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " kx", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", " kz", nullptr));
        scale_btn->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "ay", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "az", nullptr));
        rotate_btn->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ax", nullptr));
        down_btn->setText(QCoreApplication::translate("MainWindow", "\342\254\207", nullptr));
        change_model_btn->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Current figure:", nullptr));
        curr_model_lbl->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        change_camera_btn->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Current camera:", nullptr));
        curr_camera_lbl->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        remove_object_btn->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        clear_scene_btn->setText(QCoreApplication::translate("MainWindow", "Clear scene", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNWODTXS_H
