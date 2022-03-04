#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

#include "myscene.h"
#include "figure.h"
#include "points_convertions.h"
#include "constants.h"
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fileButton_clicked();

    void on_scaleButton_clicked();

    void on_trasferButton_clicked();

    void on_angleButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::MainWindow *ui;
    myscene_t scene;
    struct figure_t fig;
    struct data dataaction;
};
#endif // MAINWINDOW_H
