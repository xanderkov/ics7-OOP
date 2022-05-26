#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_scene();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup_scene()
{
    scene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene(this));
    ui->graphicsView->setScene(scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    std::shared_ptr<AbstractFactory> factory(new Factory(scene));
    drawer = factory->create();
}

void MainWindow::render_scene()
{
    drawer->clear();
    shared_ptr<BaseCommand> command(new DrawScene(drawer));

    facade.execute(command);
}


void MainWindow::on_load_scene_button_clicked()
{
    try
    {
        string file = QFileDialog::getOpenFileName(this, tr("Open scene file"), "", tr("Text file (*.txt)")).toStdString();
        shared_ptr<BaseCommand> command(new LoadScene(file));

        facade.execute(command);

        //render_scene();
    }
    catch (exception &error)
    {
        cout << error.what();
        QMessageBox::information(this, "Ошибка", "Ошибка чтения файла");
    }
}


void MainWindow::on_install_camera_button_clicked()
{
    try
    {
        int num = ui->Cam_E->text().toInt();

        shared_ptr<BaseCommand> command(new SetCamera(num));

        facade.execute(command);
        render_scene();
    }
    catch (exception &error)
    {
        cout << error.what();
    }
}


void MainWindow::on_load_figur_button_clicked()
{
    try
    {
        string file = QFileDialog::getOpenFileName(this, tr("Open scene file"), "", tr("Text file (*.txt)")).toStdString();
        shared_ptr<BaseCommand> command(new LoadFigure(string(file)));

        facade.execute(command);
        render_scene();
    }
    catch(exception &error)
    {
        cout << error.what();
        QMessageBox::information(this, "Ошибка", "Ошибка чтения файла");
    }
}


void MainWindow::on_load_camera_button_clicked()
{
    try
    {
        string file = QFileDialog::getOpenFileName(this, tr("Open scene file"), "", tr("Text file (*.txt)")).toStdString();
        shared_ptr<BaseCommand> command(new LoadCamera(string(file)));

        facade.execute(command);
        render_scene();
    }
    catch (exception &error)
    {
        cout << error.what();
        QMessageBox::information(this, "Ошибка", "Ошибка чтения файла");
    }
}


void MainWindow::on_move_figure_button_clicked()
{
    try
    {
        int num = ui->N_L->text().toInt();

        double x = ui->X_E->text().toDouble();
        double y = ui->Y_E->text().toDouble();
        double z = ui->Z_E->text().toDouble();


        shared_ptr<BaseCommand> command(new TransferObject(num, Point(x, y, z)));

        facade.execute(command);
        render_scene();
    }
    catch (exception &error)
    {
        cout << error.what();
    }
}


void MainWindow::on_rotate_figure_button_clicked()
{
    try
    {
        int num = ui->N_L_2->text().toInt();

        double x = ui->X_E_2->text().toDouble();
        double y = ui->Y_E_2->text().toDouble();
        double z = ui->Z_E_2->text().toDouble();


        shared_ptr<BaseCommand> command(new RotateObject(num, Angle(x, y, z)));

        facade.execute(command);
        render_scene();
    }
    catch (exception &error)
    {
        cout << error.what();
    }
}


void MainWindow::on_scale_figure_button_clicked()
{
    try
    {
        int num = ui->N_L_3->text().toInt();

        double x = ui->X_E_3->text().toDouble();
        double y = ui->Y_E_3->text().toDouble();
        double z = ui->Z_E_3->text().toDouble();


        shared_ptr<BaseCommand> command(new ScaleObject(num, ScaleCoef(x, y, z)));

        facade.execute(command);
        render_scene();
    }
    catch (exception &error)
    {
        cout << error.what();
    }
}


void MainWindow::on_pushButton_clicked()
{
    try
    {
        shared_ptr<BaseCommand> command(new RemoveObject(0));

        facade.execute(command);
        render_scene();
    }
    catch (exception &error)
    {
        cout << error.what();
        QMessageBox::information(this, "Ошибка", "Нет моделей");
    }
}

