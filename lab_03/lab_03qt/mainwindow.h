#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <memory>

#include "command_base.h"
#include "commands.h"
#include "drawer_qt.h"
#include "facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    class DrawDirector
    {
        friend class MainWindow;

    private:
        std::shared_ptr<QGraphicsScene> _scene_view;

    public:
        DrawDirector() = default;
        void set_scene(std::shared_ptr<QGraphicsScene> &scene_view) { this->_scene_view = scene_view; }
        std::shared_ptr<BaseDrawer> get_drawer(const char *fp, std::shared_ptr<AbstractFactory> &f);
    };

    class SourceDirector
    {
        friend class MainWindow;
    public:
        SourceDirector() = default;
        std::shared_ptr<BaseModelSourceLoader> get_loader_model(const char *fp);
        std::shared_ptr<BaseCameraSourceLoader> get_loader_camera(const char *fp);
    };

private slots:
    void on_pushButton_AddCamera_clicked();

    void on_pushButton_AddModel_clicked();

    void on_pushButton_RemoveCamera_clicked();

    void on_pushButton_SetCamera_clicked();

    void on_pushButton_RemoveModel_clicked();

    void on_pushButton_moveCamera_clicked();

    void on_pushButton_rotateCamera_clicked();

    void on_pushButton_moveModel_clicked();

    void on_pushButton_rotateModel_clicked();

    void on_pushButton_scaleModel_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> scene_view;
    DrawDirector director;
    SourceDirector sdirector;
    std::unique_ptr<Facade> facade_viewer;
    size_t index_model;
    size_t index_camera;
    friend class DrawDirector;
    char *development_environment;
    void render();
    std::string readConfigFileDrawer(const char *filename);
    std::string readConfigFileSource(const char *filename);
};
#endif // MAINWINDOW_H
