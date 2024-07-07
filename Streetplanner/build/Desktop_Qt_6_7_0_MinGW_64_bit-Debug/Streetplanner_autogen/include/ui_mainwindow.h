/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionClear_Scene;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Input;
    QPushButton *pushButton_Input;
    QLabel *label_Input;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_TestAbstractMap;
    QPushButton *pushButton_TestDrawMapWithCities;
    QPushButton *pushButton_TestDrawFullMap;
    QCheckBox *checkBox_HideTestButtons;
    QPushButton *pushButton_FillMap;
    QPushButton *pushButton_AddCity;
    QPushButton *pushButton_TestDrawStreet;
    QPushButton *pushButton_Wayfinder;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_TestDrawCity;
    QPushButton *pushButton_TestDijkstra;
    QPushButton *pushButton_AddStreet;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuScene;
    QMenu *menuInfo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(920, 763);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionOpen->setEnabled(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setIconVisibleInMenu(true);
        actionClear_Scene = new QAction(MainWindow);
        actionClear_Scene->setObjectName("actionClear_Scene");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(10);
        lineEdit_Input = new QLineEdit(centralwidget);
        lineEdit_Input->setObjectName("lineEdit_Input");
        lineEdit_Input->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEdit_Input, 1, 0, 1, 1);

        pushButton_Input = new QPushButton(centralwidget);
        pushButton_Input->setObjectName("pushButton_Input");

        gridLayout->addWidget(pushButton_Input, 2, 0, 1, 1);

        label_Input = new QLabel(centralwidget);
        label_Input->setObjectName("label_Input");

        gridLayout->addWidget(label_Input, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 1, 15, 1);

        pushButton_TestAbstractMap = new QPushButton(centralwidget);
        pushButton_TestAbstractMap->setObjectName("pushButton_TestAbstractMap");

        gridLayout->addWidget(pushButton_TestAbstractMap, 12, 0, 1, 1);

        pushButton_TestDrawMapWithCities = new QPushButton(centralwidget);
        pushButton_TestDrawMapWithCities->setObjectName("pushButton_TestDrawMapWithCities");

        gridLayout->addWidget(pushButton_TestDrawMapWithCities, 9, 0, 1, 1);

        pushButton_TestDrawFullMap = new QPushButton(centralwidget);
        pushButton_TestDrawFullMap->setObjectName("pushButton_TestDrawFullMap");

        gridLayout->addWidget(pushButton_TestDrawFullMap, 11, 0, 1, 1);

        checkBox_HideTestButtons = new QCheckBox(centralwidget);
        checkBox_HideTestButtons->setObjectName("checkBox_HideTestButtons");

        gridLayout->addWidget(checkBox_HideTestButtons, 7, 0, 1, 1);

        pushButton_FillMap = new QPushButton(centralwidget);
        pushButton_FillMap->setObjectName("pushButton_FillMap");

        gridLayout->addWidget(pushButton_FillMap, 5, 0, 1, 1);

        pushButton_AddCity = new QPushButton(centralwidget);
        pushButton_AddCity->setObjectName("pushButton_AddCity");

        gridLayout->addWidget(pushButton_AddCity, 3, 0, 1, 1);

        pushButton_TestDrawStreet = new QPushButton(centralwidget);
        pushButton_TestDrawStreet->setObjectName("pushButton_TestDrawStreet");

        gridLayout->addWidget(pushButton_TestDrawStreet, 10, 0, 1, 1);

        pushButton_Wayfinder = new QPushButton(centralwidget);
        pushButton_Wayfinder->setObjectName("pushButton_Wayfinder");

        gridLayout->addWidget(pushButton_Wayfinder, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 14, 0, 1, 1);

        pushButton_TestDrawCity = new QPushButton(centralwidget);
        pushButton_TestDrawCity->setObjectName("pushButton_TestDrawCity");

        gridLayout->addWidget(pushButton_TestDrawCity, 8, 0, 1, 1);

        pushButton_TestDijkstra = new QPushButton(centralwidget);
        pushButton_TestDijkstra->setObjectName("pushButton_TestDijkstra");

        gridLayout->addWidget(pushButton_TestDijkstra, 13, 0, 1, 1);

        pushButton_AddStreet = new QPushButton(centralwidget);
        pushButton_AddStreet->setObjectName("pushButton_AddStreet");

        gridLayout->addWidget(pushButton_AddStreet, 4, 0, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 920, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuScene = new QMenu(menubar);
        menuScene->setObjectName("menuScene");
        menuInfo = new QMenu(menubar);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuScene->menuAction());
        menubar->addAction(menuInfo->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuScene->addAction(actionClear_Scene);
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear_Scene->setText(QCoreApplication::translate("MainWindow", "Clear Scene", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "Written by", nullptr));
        lineEdit_Input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Input", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Input->setToolTip(QCoreApplication::translate("MainWindow", "send the Input", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Input->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        label_Input->setText(QCoreApplication::translate("MainWindow", "Input here:", nullptr));
        pushButton_TestAbstractMap->setText(QCoreApplication::translate("MainWindow", "Test Abstract Map", nullptr));
        pushButton_TestDrawMapWithCities->setText(QCoreApplication::translate("MainWindow", "Test Draw Map", nullptr));
        pushButton_TestDrawFullMap->setText(QCoreApplication::translate("MainWindow", "Test Draw Full Map", nullptr));
        checkBox_HideTestButtons->setText(QCoreApplication::translate("MainWindow", "Hide TestButtons", nullptr));
        pushButton_FillMap->setText(QCoreApplication::translate("MainWindow", "Fill Map", nullptr));
        pushButton_AddCity->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        pushButton_TestDrawStreet->setText(QCoreApplication::translate("MainWindow", "Test Draw Street", nullptr));
        pushButton_Wayfinder->setText(QCoreApplication::translate("MainWindow", "Wayfinder", nullptr));
        pushButton_TestDrawCity->setText(QCoreApplication::translate("MainWindow", "Test Draw City", nullptr));
        pushButton_TestDijkstra->setText(QCoreApplication::translate("MainWindow", "Test Dijkstra", nullptr));
        pushButton_AddStreet->setText(QCoreApplication::translate("MainWindow", "Add Street", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuScene->setTitle(QCoreApplication::translate("MainWindow", "Scene", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
