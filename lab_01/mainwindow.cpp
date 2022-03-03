#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene.scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene.scene);
    fig.arr = NULL;
    fig.matrix = NULL;
    fig.n = 0;
}

MainWindow::~MainWindow()
{
    delete [] fig.arr;
    free_matrix(fig.matrix, fig.n);
    delete ui;
}


void MainWindow::on_fileButton_clicked()
{
    QString text = ui->fileEdit->text();

    std::string str = text.toStdString();
    dataaction.filename = str.c_str();
    rc_type rc = controller(scene, DOWNLOAD, dataaction);
    if (rc)
        print_warning(rc);
    rc = controller(scene, DRAW, dataaction);
    if (rc)
        print_warning(rc);
}


void MainWindow::on_scaleButton_clicked()
{
    double km = ui->scaleEdit->value();
    dataaction.scale.k = km;
    rc_type rc = controller(scene, SCALE, dataaction);
    if (rc)
        print_warning(rc);
    rc = controller(scene, DRAW, dataaction);
    if (rc)
        print_warning(rc);
}


void MainWindow::on_trasferButton_clicked()
{

}


void MainWindow::on_angleButton_clicked()
{

}


void MainWindow::on_returnButton_clicked()
{

}

