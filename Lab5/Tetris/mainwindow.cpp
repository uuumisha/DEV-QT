#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->display(0);
    emit SignalGlassInit();
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(ShowAbout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotClearScore() {
    ui->lcdNumber->display(0);
}

void MainWindow::ShowAbout() {
    QMessageBox msgBox;
    msgBox.setText("This Is Tetris Game!\n Press New Game and Enjoy!");
    msgBox.exec();
}
