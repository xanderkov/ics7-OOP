#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(500, 500);
    this->_layout= std::unique_ptr<QVBoxLayout>(new QVBoxLayout);

    this->ui->centralwidget->setLayout(this->_layout.get());

    this->_layout->addWidget(this->my_lift.widget());
}

MainWindow::~MainWindow()
{
    delete ui;
}

