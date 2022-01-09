/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glass.h"
#include "nextfigure.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionNew_Game;
    QWidget *centralwidget;
    Glass *WidgetGlass;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonNewGame;
    QPushButton *pushButtonExit;
    QSpacerItem *verticalSpacer_2;
    QLabel *scoreLabel;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelNextFigure;
    NextFigure *nextFigure;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(543, 533);
        MainWindow->setMinimumSize(QSize(30, 80));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/images/Tetris.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/images/iconExit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/images/iconInfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/images/newgame.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Game->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        WidgetGlass = new Glass(centralwidget);
        WidgetGlass->setObjectName(QString::fromUtf8("WidgetGlass"));
        WidgetGlass->setGeometry(QRect(140, 30, 201, 391));
        WidgetGlass->setFocusPolicy(Qt::StrongFocus);
        WidgetGlass->setProperty("rows", QVariant(20u));
        WidgetGlass->setProperty("columns", QVariant(12u));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(367, 31, 141, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonNewGame = new QPushButton(layoutWidget);
        pushButtonNewGame->setObjectName(QString::fromUtf8("pushButtonNewGame"));
        pushButtonNewGame->setIcon(icon3);

        verticalLayout->addWidget(pushButtonNewGame);

        pushButtonExit = new QPushButton(layoutWidget);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setIcon(icon1);

        verticalLayout->addWidget(pushButtonExit);

        verticalSpacer_2 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        scoreLabel = new QLabel(layoutWidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setLayoutDirection(Qt::LeftToRight);
        scoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(scoreLabel);

        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setDigitCount(5);

        verticalLayout->addWidget(lcdNumber);

        verticalSpacer_3 = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 32, 102, 229));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelNextFigure = new QLabel(layoutWidget1);
        labelNextFigure->setObjectName(QString::fromUtf8("labelNextFigure"));
        labelNextFigure->setMinimumSize(QSize(50, 30));
        labelNextFigure->setFrameShape(QFrame::WinPanel);
        labelNextFigure->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelNextFigure);

        nextFigure = new NextFigure(layoutWidget1);
        nextFigure->setObjectName(QString::fromUtf8("nextFigure"));
        nextFigure->setMinimumSize(QSize(100, 100));

        verticalLayout_2->addWidget(nextFigure);

        verticalSpacer = new QSpacerItem(20, 188, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 543, 21));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuGame->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuGame->addAction(actionNew_Game);
        menuGame->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionNew_Game);
        toolBar->addAction(actionAbout);
        toolBar->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonExit, &QPushButton::clicked, MainWindow, &QMainWindow::close);
        QObject::connect(pushButtonNewGame, &QPushButton::clicked, WidgetGlass, &Glass::startGame);
        QObject::connect(WidgetGlass, SIGNAL(SetScore(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(MainWindow, SIGNAL(SignalGlassInit()), WidgetGlass, SLOT(GlassInit()));
        QObject::connect(pushButtonNewGame, SIGNAL(clicked()), MainWindow, SLOT(SlotClearScore()));
        QObject::connect(WidgetGlass, SIGNAL(PaintNextFigure(Figure*)), nextFigure, SLOT(slotChangePattern(Figure*)));
        QObject::connect(actionExit, &QAction::triggered, MainWindow, &QMainWindow::close);
        QObject::connect(actionNew_Game, &QAction::triggered, WidgetGlass, &Glass::startGame);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionNew_Game->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        pushButtonNewGame->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        scoreLabel->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        labelNextFigure->setText(QCoreApplication::translate("MainWindow", "Next Figure", nullptr));
        menuGame->setTitle(QCoreApplication::translate("MainWindow", "Game", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
