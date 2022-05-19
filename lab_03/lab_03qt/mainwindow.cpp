#include "mainwindow.h"
#include "ui_mainwindow.h"



#include "canvas_qt.h"
#include "factory_qt.h"
#include "model_source_loader_file.h"
#include "camera_source_loader_file.h"
#include "error_new.h"
#include "error_loader.h"

#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , facade_viewer(new Facade)
    , index_model(0)
    , index_camera(0)
{
    ui->setupUi(this);
    scene_view = std::make_shared<QGraphicsScene>();
    director.set_scene(scene_view);
    ui->graphicsView->setScene(scene_view.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::render()
{
    if (ui->comboBoxCamera->count() == 0)
        QMessageBox::information(nullptr, "Warning", "Choose camera to render");
    time_t t_time = time(NULL);
    std::shared_ptr<AbstractFactory> factory;
    auto drawer = director.get_drawer("F:/Projects/ics7-OOP/lab_03/lab_03qt/data/config.cfg", factory);

    if (drawer == nullptr)
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    std::shared_ptr<BaseCommand> command(new DrawCommand(drawer));
    facade_viewer->RunCommand(command);

    ui->graphicsView->setScene(this->scene_view.get());
}


void MainWindow::on_pushButton_AddCamera_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                QString::fromUtf8("Открыть файл"),
                                                QDir::currentPath(),
                                                "text files (*.txt)");
    if (file.isEmpty())
        return;

    std::string camera_name = std::string("camer_") + std::to_string(++index_camera);
    std::string file_name = file.toLocal8Bit().constData();

    time_t t_time = time(NULL);
    auto loader = sdirector.get_loader_camera("F:/Projects/ics7-OOP/lab_03/lab_03qt/data/config.cfg");

    if (loader == nullptr)
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    try
    {
        std::shared_ptr<BaseCommand> command(new AddCameraCommand(camera_name, file_name, loader));
        facade_viewer->RunCommand(command);
        ui->comboBoxCamera->addItem(camera_name.c_str());
        on_pushButton_SetCamera_clicked();
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }

}


void MainWindow::on_pushButton_AddModel_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                QString::fromUtf8("Открыть файл"),
                                                QDir::currentPath(),
                                                "text files (*.txt)");
    if (file.isEmpty())
    {
        return;
    }

    std::string model_name = std::string("model_") + std::to_string(++index_model);
    std::string file_name = file.toLocal8Bit().constData();

    time_t t_time = time(NULL);

    auto loader = sdirector.get_loader_model("F:/Projects/ics7-OOP/lab_03/lab_03qt/data/config.cfg");

    if (loader == nullptr)
    {
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    try
    {
        std::shared_ptr<BaseCommand> command(new AddModelCommand(model_name, file_name, loader));
        facade_viewer->RunCommand(command);
        render();
        ui->comboBoxModel->addItem(model_name.c_str());
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}


void MainWindow::on_pushButton_RemoveCamera_clicked()
{
    if (ui->comboBoxCamera->count() == 0)
        return;

    try
    {
        std::string cam_name = ui->comboBoxCamera->currentText().toStdString();
        std::shared_ptr<BaseCommand> command(new RemoveObjectCommand(cam_name));
        facade_viewer->RunCommand(command);
        ui->comboBoxCamera->removeItem(ui->comboBoxCamera->currentIndex());
        if (ui->comboBoxCamera->count() == 0)
        {
            QMessageBox::information(nullptr, "Warning", "Choose camera to render");
            scene_view->clear();

            return;
        }
        render();
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}


void MainWindow::on_pushButton_SetCamera_clicked()
{
    std::string cam_name = ui->comboBoxCamera->currentText().toStdString();
    try
    {
        std::shared_ptr<BaseCommand> command(new SetCameraCommand(cam_name));
        facade_viewer->RunCommand(command);

        if (ui->comboBoxCamera->count() > 0)
            render();
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}


void MainWindow::on_pushButton_RemoveModel_clicked()
{
    if (ui->comboBoxModel->count() == 0)
        return;

    try
    {
        std::string model_name = ui->comboBoxModel->currentText().toStdString();
        std::shared_ptr<BaseCommand> command(new RemoveObjectCommand(model_name));
        facade_viewer->RunCommand(command);
        ui->comboBoxModel->removeItem(ui->comboBoxModel->currentIndex());
        if (ui->comboBoxCamera->count() == 0)
        {
            QMessageBox::information(nullptr, "Warning", "Choose camera to render");
            scene_view->clear();

            return;
        }
        if (ui->comboBoxModel->count() == 0)
        {
            scene_view->clear();
            return;
        }
        render();
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

std::string MainWindow::readConfigFileSource(const char *filename)
{
    std::ifstream file_;
    time_t t_time = time(NULL);

    file_.open(filename);
    if (!file_)
    {
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    std::string dev_file;
    std::getline(file_, dev_file);
    std::getline(file_, dev_file);
    file_.close();

    return dev_file;
}



void MainWindow::on_pushButton_moveCamera_clicked()
{
    if (ui->comboBoxModel->count() == 0)
    {
        return;
    }

    std::string cam_name = ui->comboBoxCamera->currentText().toStdString();
    double x = ui->doubleSpinBoxDx_c->value();
    double y = ui->doubleSpinBoxDy_c->value();
    double z = ui->doubleSpinBoxDz_c->value();

    try
    {
        Point<double> moving(x, y, z);
        Point<double> rotateing(0, 0, 0);
        Point<double> scale(1, 1, 1);
        std::shared_ptr<BaseCommand> command(new TransformObjectCommand(cam_name, moving, scale, rotateing));
        facade_viewer->RunCommand(command);
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }

    render();
}


void MainWindow::on_pushButton_rotateCamera_clicked()
{
    if (ui->comboBoxModel->count() == 0)
    {
        return;
    }

    std::string cam_name = ui->comboBoxCamera->currentText().toStdString();
    double angle_x = ui->doubleSpinBoxOx_c->value();
    double angle_y = ui->doubleSpinBoxOy_c->value();
    double angle_z = ui->doubleSpinBoxOz_c->value();

    try
    {
        Point<double> moving(0, 0, 0);
        Point<double> rotateing(angle_x, angle_y, angle_z);
        Point<double> scale(1, 1, 1);
        std::shared_ptr<BaseCommand> command(new TransformObjectCommand(cam_name, moving, scale, rotateing));
        facade_viewer->RunCommand(command);
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }

    render();
}


void MainWindow::on_pushButton_moveModel_clicked()
{
    if (ui->comboBoxModel->count() == 0)
    {
        return;
    }

    std::string obj_name = ui->comboBoxModel->currentText().toStdString();
    double x = ui->doubleSpinBoxDx->value();
    double y = ui->doubleSpinBoxDy->value();
    double z = ui->doubleSpinBoxDz->value();

    try
    {
        Point<double> moving(x, y, z);
        Point<double> rotateing(0, 0, 0);
        Point<double> scale(1, 1, 1);
        std::shared_ptr<BaseCommand> command(new TransformObjectCommand(obj_name, moving, scale, rotateing));
        facade_viewer->RunCommand(command);
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }

    render();
}


void MainWindow::on_pushButton_rotateModel_clicked()
{
    if (ui->comboBoxModel->count() == 0)
    {
        return;
    }

    std::string obj_name = ui->comboBoxModel->currentText().toStdString();
    double x = ui->doubleSpinBoxOx->value();
    double y = ui->doubleSpinBoxOy->value();
    double z = ui->doubleSpinBoxOz->value();

    try
    {
        Point<double> moving(0, 0, 0);
        Point<double> rotateing(x, y, z);
        Point<double> scale(1, 1, 1);
        std::shared_ptr<BaseCommand> command(new TransformObjectCommand(obj_name, moving, scale, rotateing));
        facade_viewer->RunCommand(command);
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }

    render();
}


void MainWindow::on_pushButton_scaleModel_clicked()
{
    if (ui->comboBoxModel->count() == 0)
        return;

    std::string obj_name = ui->comboBoxModel->currentText().toStdString();
    double x = ui->doubleSpinBoxDx->value();
    double y = ui->doubleSpinBoxDy->value();
    double z = ui->doubleSpinBoxDz->value();

    try
    {
        Point<double> moving(x, y, z);
        Point<double> rotateing(0, 0, 0);
        Point<double> scale(1, 1, 1);
        std::shared_ptr<BaseCommand> command(new TransformObjectCommand(obj_name, moving, scale, rotateing));
        facade_viewer->RunCommand(command);
    }
    catch (DefaultException &ex)
    {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }

    render();
}

