#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    testView = new TestView;

    this->setCentralWidget(testView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

