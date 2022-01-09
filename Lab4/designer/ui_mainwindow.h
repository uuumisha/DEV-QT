/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mypicture.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Exit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    MyPicture *widget;
    QSpinBox *spinbox;
    QPushButton *pushButtonExit;
    QLabel *editbuddy;
    QSlider *slider;
    QLabel *slyderbuddy;
    QLabel *spinbuddy;
    QLineEdit *lineEdit;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuInformation;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(646, 424);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/icon1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        action_Exit->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/icon2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/iconInfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new MyPicture(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setCursor(QCursor(Qt::PointingHandCursor));
        widget->setAutoFillBackground(false);

        gridLayout->addWidget(widget, 3, 0, 1, 4);

        spinbox = new QSpinBox(centralwidget);
        spinbox->setObjectName(QString::fromUtf8("spinbox"));
        spinbox->setMaximum(100);
        spinbox->setValue(50);

        gridLayout->addWidget(spinbox, 0, 0, 1, 1);

        pushButtonExit = new QPushButton(centralwidget);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Pictures/Disney_42.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExit->setIcon(icon3);

        gridLayout->addWidget(pushButtonExit, 0, 4, 1, 1);

        editbuddy = new QLabel(centralwidget);
        editbuddy->setObjectName(QString::fromUtf8("editbuddy"));
        editbuddy->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(editbuddy, 1, 3, 1, 1);

        slider = new QSlider(centralwidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setMaximum(100);
        slider->setSingleStep(1);
        slider->setValue(50);
        slider->setOrientation(Qt::Horizontal);
        slider->setTickPosition(QSlider::TicksBelow);
        slider->setTickInterval(5);

        gridLayout->addWidget(slider, 2, 0, 1, 3);

        slyderbuddy = new QLabel(centralwidget);
        slyderbuddy->setObjectName(QString::fromUtf8("slyderbuddy"));
        slyderbuddy->setFrameShape(QFrame::StyledPanel);
        slyderbuddy->setMidLineWidth(0);
        slyderbuddy->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(slyderbuddy, 2, 3, 1, 1);

        spinbuddy = new QLabel(centralwidget);
        spinbuddy->setObjectName(QString::fromUtf8("spinbuddy"));
        spinbuddy->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(spinbuddy, 0, 3, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setEnabled(true);
        statusbar->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menuInformation = new QMenu(menuBar);
        menuInformation->setObjectName(QString::fromUtf8("menuInformation"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
#if QT_CONFIG(shortcut)
        editbuddy->setBuddy(lineEdit);
        slyderbuddy->setBuddy(slider);
        spinbuddy->setBuddy(spinbox);
#endif // QT_CONFIG(shortcut)

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuInformation->menuAction());
        menu_File->addAction(action_Exit);
        menuInformation->addAction(actionAbout);
        toolBar->addAction(action_Exit);

        retranslateUi(MainWindow);
        QObject::connect(spinbox, &QSpinBox::valueChanged, slider, &QSlider::setValue);
        QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), MainWindow, SLOT(lineEditSlot(QString)));
        QObject::connect(spinbox, SIGNAL(valueChanged(int)), MainWindow, SLOT(lineEditSet(int)));
        QObject::connect(pushButtonExit, &QPushButton::clicked, MainWindow, &QMainWindow::close);
        QObject::connect(slider, SIGNAL(valueChanged(int)), widget, SLOT(ScaleChanged(int)));
        QObject::connect(action_Exit, &QAction::triggered, MainWindow, &QMainWindow::close);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Designer", nullptr));
#if QT_CONFIG(statustip)
        MainWindow->setStatusTip(QCoreApplication::translate("MainWindow", "Do nothing", nullptr));
#endif // QT_CONFIG(statustip)
        action_Exit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
#if QT_CONFIG(shortcut)
        action_Exit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        editbuddy->setText(QCoreApplication::translate("MainWindow", "&EditBuddy", nullptr));
        slyderbuddy->setText(QCoreApplication::translate("MainWindow", "&SliderBuddy", nullptr));
        spinbuddy->setText(QCoreApplication::translate("MainWindow", "&SpinBuddy", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuInformation->setTitle(QCoreApplication::translate("MainWindow", "Information", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
