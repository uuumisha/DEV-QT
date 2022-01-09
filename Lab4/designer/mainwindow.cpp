#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Status Bar");

    ui->spinbox->setFixedSize(ui->spinbox->sizeHint());
    ui->lineEdit->setFixedSize(ui->spinbox->sizeHint());

    QIntValidator *validator = new QIntValidator(0, 100, ui->lineEdit);
    validator->setRange(0,100);
    ui->lineEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lineEditSlot(QString str) {
    ui->slider->setValue(str.toInt());
}

void MainWindow::lineEditSet(int val) {
    ui->lineEdit->setText(QString::number(val));
    ui->statusbar->showMessage(QString::number(val));
}

void MainWindow::on_actionAbout_triggered()
{
    //QIcon icon(":/Icons/iconInfo.ico");
    //QMessageBox msgBox(icon, "This app about", "Designer for show picture");

    QMessageBox::about(this, "This app about", "Designer for show picture");
}
