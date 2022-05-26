#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>

#include "../facade/basecommand.h"
#include "../facade/facade.h"
#include "../abstractfactory/abstractfactory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setup_scene();
    void render_scene();

private slots:


    void on_load_scene_button_clicked();

    void on_install_camera_button_clicked();

    void on_load_figur_button_clicked();

    void on_load_camera_button_clicked();

    void on_move_figure_button_clicked();

    void on_rotate_figure_button_clicked();

    void on_scale_figure_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    shared_ptr<QGraphicsScene> scene;
    shared_ptr<BaseDrawer> drawer;

    Facade facade;
};
#endif // MAINWINDOW_H
