/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionDark;
    QAction *actionLight;
    QAction *actionBlue;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *eraseButton;
    QPushButton *eyedropButton;
    QPushButton *marqueeButton;
    QPushButton *drawButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *canvas;
    QGroupBox *groupBox_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *editor;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuThemes;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(810, 480);
        MainWindow->setMinimumSize(QSize(320, 240));
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName(QStringLiteral("actionDark"));
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName(QStringLiteral("actionLight"));
        actionBlue = new QAction(MainWindow);
        actionBlue->setObjectName(QStringLiteral("actionBlue"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 200, 100));
        eraseButton = new QPushButton(groupBox);
        eraseButton->setObjectName(QStringLiteral("eraseButton"));
        eraseButton->setGeometry(QRect(100, 0, 72, 45));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qml/Editing-Eraser-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraseButton->setIcon(icon);
        eyedropButton = new QPushButton(groupBox);
        eyedropButton->setObjectName(QStringLiteral("eyedropButton"));
        eyedropButton->setGeometry(QRect(100, 50, 72, 45));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/qml/Eyedropper-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        eyedropButton->setIcon(icon1);
        marqueeButton = new QPushButton(groupBox);
        marqueeButton->setObjectName(QStringLiteral("marqueeButton"));
        marqueeButton->setGeometry(QRect(0, 50, 72, 45));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/qml/cell-6-2-480.png"), QSize(), QIcon::Normal, QIcon::Off);
        marqueeButton->setIcon(icon2);
        drawButton = new QPushButton(groupBox);
        drawButton->setObjectName(QStringLiteral("drawButton"));
        drawButton->setGeometry(QRect(0, 0, 72, 45));
        drawButton->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/qml/1024px-Black_pencil.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawButton->setIcon(icon3);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(160, 90, 160, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        canvas = new QWidget(groupBox);
        canvas->setObjectName(QStringLiteral("canvas"));
        canvas->setGeometry(QRect(0, 0, 390, 390));
        canvas->setMouseTracking(true);
        canvas->setAutoFillBackground(false);
        canvas->raise();
        eraseButton->raise();
        eyedropButton->raise();
        marqueeButton->raise();
        drawButton->raise();
        horizontalLayoutWidget->raise();
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(600, 0, 200, 220));
        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(600, 220, 200, 340));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 198, 338));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        editor = new QWidget(centralWidget);
        editor->setObjectName(QStringLiteral("editor"));
        editor->setEnabled(true);
        editor->setGeometry(QRect(200, 0, 100, 559));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editor->sizePolicy().hasHeightForWidth());
        editor->setSizePolicy(sizePolicy);
        editor->setMaximumSize(QSize(167, 16770));
        editor->setMouseTracking(false);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 100, 200, 81));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 198, 79));
        scrollArea->setWidget(scrollAreaWidgetContents);
        dockWidget_2 = new QDockWidget(centralWidget);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setGeometry(QRect(0, 180, 200, 261));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidget_2->sizePolicy().hasHeightForWidth());
        dockWidget_2->setSizePolicy(sizePolicy1);
        dockWidget_2->setMinimumSize(QSize(80, 201));
        dockWidget_2->setMaximumSize(QSize(200, 261));
        dockWidget_2->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        dockWidget_2->setWidget(dockWidgetContents_4);
        MainWindow->setCentralWidget(centralWidget);
        scrollArea->raise();
        groupBox->raise();
        groupBox_3->raise();
        scrollArea_2->raise();
        editor->raise();
        dockWidget_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 810, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuThemes = new QMenu(menuBar);
        menuThemes->setObjectName(QStringLiteral("menuThemes"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuThemes->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuThemes->addAction(actionDark);
        menuThemes->addAction(actionLight);
        menuThemes->addAction(actionBlue);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionDark->setText(QApplication::translate("MainWindow", "Dark", 0));
        actionLight->setText(QApplication::translate("MainWindow", "Light", 0));
        actionBlue->setText(QApplication::translate("MainWindow", "Blue", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        eraseButton->setText(QString());
        eyedropButton->setText(QString());
        marqueeButton->setText(QString());
        drawButton->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuThemes->setTitle(QApplication::translate("MainWindow", "Themes", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
