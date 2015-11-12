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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <preview.h>
#include "canvas.h"

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
    QAction *actionOpen;
    QAction *actionSprite_Properties;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *eyedropButton;
    QPushButton *marqueeButton;
    QPushButton *drawButton;
    QLabel *label_3;
    QPushButton *eraseButton;
    Canvas *canvas;
    QGroupBox *preview_box;
    QLabel *fps_label;
    QRadioButton *pingPongButton;
    QRadioButton *loopButton;
    QLabel *label;
    Preview *preview_window;
    QSlider *fpsSlider;
    QLabel *label_4;
    QGroupBox *frames_box;
    QListWidget *listWidget;
    QPushButton *copyFrameButton;
    QPushButton *deleteFrameButton;
    QPushButton *onionSkinButton;
    QLabel *frames_label;
    QPushButton *newFrameButton;
    QGroupBox *color_box;
    QLabel *label_5;
    QScrollArea *colorSelectorScroller;
    QWidget *scrollAreaWidgetContents_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuThemes;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 522);
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
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSprite_Properties = new QAction(MainWindow);
        actionSprite_Properties->setObjectName(QStringLiteral("actionSprite_Properties"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 200, 141));
        groupBox->setStyleSheet(QStringLiteral("border: 1px solid;"));
        eyedropButton = new QPushButton(groupBox);
        eyedropButton->setObjectName(QStringLiteral("eyedropButton"));
        eyedropButton->setGeometry(QRect(110, 90, 81, 41));
        QIcon icon;
        icon.addFile(QStringLiteral(":/qml/Eyedropper-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        eyedropButton->setIcon(icon);
        marqueeButton = new QPushButton(groupBox);
        marqueeButton->setObjectName(QStringLiteral("marqueeButton"));
        marqueeButton->setEnabled(false);
        marqueeButton->setGeometry(QRect(10, 90, 81, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/qml/cell-6-2-480.png"), QSize(), QIcon::Normal, QIcon::Off);
        marqueeButton->setIcon(icon1);
        drawButton = new QPushButton(groupBox);
        drawButton->setObjectName(QStringLiteral("drawButton"));
        drawButton->setGeometry(QRect(10, 40, 81, 45));
        drawButton->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/qml/1024px-Black_pencil.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawButton->setIcon(icon2);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 81, 21));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("border: 0px;\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        eraseButton = new QPushButton(groupBox);
        eraseButton->setObjectName(QStringLiteral("eraseButton"));
        eraseButton->setGeometry(QRect(110, 40, 81, 45));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/qml/Editing-Eraser-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraseButton->setIcon(icon3);
        canvas = new Canvas(centralWidget);
        canvas->setObjectName(QStringLiteral("canvas"));
        canvas->setGeometry(QRect(240, 10, 300, 300));
        canvas->setMouseTracking(true);
        canvas->setLayoutDirection(Qt::LeftToRight);
        canvas->setStyleSheet(QLatin1String("border: 1px solid black;\n"
"background-color: white;"));
        canvas->setScaledContents(true);
        preview_box = new QGroupBox(centralWidget);
        preview_box->setObjectName(QStringLiteral("preview_box"));
        preview_box->setGeometry(QRect(570, 10, 221, 301));
        preview_box->setStyleSheet(QStringLiteral("border: 1px solid;"));
        fps_label = new QLabel(preview_box);
        fps_label->setObjectName(QStringLiteral("fps_label"));
        fps_label->setGeometry(QRect(10, 40, 41, 20));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        fps_label->setFont(font1);
        fps_label->setStyleSheet(QLatin1String("border: 0px solid black;\n"
"\n"
""));
        fps_label->setAlignment(Qt::AlignCenter);
        pingPongButton = new QRadioButton(preview_box);
        pingPongButton->setObjectName(QStringLiteral("pingPongButton"));
        pingPongButton->setGeometry(QRect(20, 260, 171, 31));
        loopButton = new QRadioButton(preview_box);
        loopButton->setObjectName(QStringLiteral("loopButton"));
        loopButton->setGeometry(QRect(20, 220, 171, 31));
        loopButton->setFont(font1);
        loopButton->setChecked(true);
        label = new QLabel(preview_box);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 81, 21));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("border: 0px;\n"
"background-color: rgba(255, 255, 255, 0);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        preview_window = new Preview(preview_box);
        preview_window->setObjectName(QStringLiteral("preview_window"));
        preview_window->setGeometry(QRect(60, 30, 141, 141));
        preview_window->setStyleSheet(QLatin1String("border: 1px solid;\n"
"background-color: rgb(255, 255, 255);"));
        preview_window->setFrameShape(QFrame::NoFrame);
        fpsSlider = new QSlider(preview_box);
        fpsSlider->setObjectName(QStringLiteral("fpsSlider"));
        fpsSlider->setGeometry(QRect(20, 70, 22, 101));
        fpsSlider->setStyleSheet(QStringLiteral("border: 0px;"));
        fpsSlider->setMaximum(24);
        fpsSlider->setValue(12);
        fpsSlider->setOrientation(Qt::Vertical);
        label_4 = new QLabel(preview_box);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 190, 131, 21));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral("border: 0px;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        frames_box = new QGroupBox(centralWidget);
        frames_box->setObjectName(QStringLiteral("frames_box"));
        frames_box->setGeometry(QRect(240, 320, 551, 161));
        frames_box->setStyleSheet(QStringLiteral("border: 1px solid;"));
        listWidget = new QListWidget(frames_box);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 30, 431, 121));
        QFont font3;
        font3.setPointSize(14);
        listWidget->setFont(font3);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setIconSize(QSize(64, 64));
        listWidget->setTextElideMode(Qt::ElideMiddle);
        listWidget->setMovement(QListView::Static);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setResizeMode(QListView::Fixed);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setModelColumn(0);
        listWidget->setUniformItemSizes(true);
        copyFrameButton = new QPushButton(frames_box);
        copyFrameButton->setObjectName(QStringLiteral("copyFrameButton"));
        copyFrameButton->setGeometry(QRect(450, 60, 91, 31));
        QFont font4;
        font4.setPointSize(10);
        copyFrameButton->setFont(font4);
        deleteFrameButton = new QPushButton(frames_box);
        deleteFrameButton->setObjectName(QStringLiteral("deleteFrameButton"));
        deleteFrameButton->setGeometry(QRect(450, 90, 91, 31));
        deleteFrameButton->setFont(font4);
        onionSkinButton = new QPushButton(frames_box);
        onionSkinButton->setObjectName(QStringLiteral("onionSkinButton"));
        onionSkinButton->setGeometry(QRect(450, 120, 91, 31));
        onionSkinButton->setFont(font4);
        frames_label = new QLabel(frames_box);
        frames_label->setObjectName(QStringLiteral("frames_label"));
        frames_label->setGeometry(QRect(10, 0, 81, 21));
        frames_label->setFont(font);
        frames_label->setStyleSheet(QLatin1String("border: 0px;\n"
"background-color: rgba(255, 255, 255, 0);"));
        frames_label->setFrameShape(QFrame::NoFrame);
        frames_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        newFrameButton = new QPushButton(frames_box);
        newFrameButton->setObjectName(QStringLiteral("newFrameButton"));
        newFrameButton->setGeometry(QRect(450, 30, 91, 31));
        newFrameButton->setFont(font4);
        newFrameButton->setCheckable(false);
        newFrameButton->setAutoDefault(false);
        newFrameButton->setFlat(false);
        color_box = new QGroupBox(centralWidget);
        color_box->setObjectName(QStringLiteral("color_box"));
        color_box->setGeometry(QRect(10, 160, 201, 321));
        color_box->setStyleSheet(QStringLiteral("border: 1px solid;"));
        label_5 = new QLabel(color_box);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 81, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QLatin1String("border: 0px;\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        colorSelectorScroller = new QScrollArea(color_box);
        colorSelectorScroller->setObjectName(QStringLiteral("colorSelectorScroller"));
        colorSelectorScroller->setGeometry(QRect(10, 40, 181, 271));
        colorSelectorScroller->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 179, 269));
        colorSelectorScroller->setWidget(scrollAreaWidgetContents_3);
        MainWindow->setCentralWidget(centralWidget);
        groupBox->raise();
        canvas->raise();
        preview_box->raise();
        label->raise();
        fps_label->raise();
        frames_box->raise();
        color_box->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
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
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionSprite_Properties);
        menuThemes->addAction(actionDark);
        menuThemes->addAction(actionLight);
        menuThemes->addAction(actionBlue);

        retranslateUi(MainWindow);
        QObject::connect(canvas, SIGNAL(mouseEvent(QMouseEvent*)), canvas, SLOT(myMousePressEvent(QMouseEvent*)));
        QObject::connect(canvas, SIGNAL(mousePressEvent(QMouseEvent*)), canvas, SLOT(myMousePressEvent(QMouseEvent*)));
        QObject::connect(canvas, SIGNAL(mouseMoveEvent(QMouseEvent*)), canvas, SLOT(myMouseMoveEvent(QMouseEvent*)));

        newFrameButton->setDefault(false);


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
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0));
        actionSprite_Properties->setText(QApplication::translate("MainWindow", "Sprite Properties", 0));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        eyedropButton->setToolTip(QApplication::translate("MainWindow", "Eyedropper", 0));
#endif // QT_NO_TOOLTIP
        eyedropButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        marqueeButton->setToolTip(QApplication::translate("MainWindow", "Selection", 0));
#endif // QT_NO_TOOLTIP
        marqueeButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        drawButton->setToolTip(QApplication::translate("MainWindow", "Pencil", 0));
#endif // QT_NO_TOOLTIP
        drawButton->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Tools", 0));
#ifndef QT_NO_TOOLTIP
        eraseButton->setToolTip(QApplication::translate("MainWindow", "Eraser", 0));
#endif // QT_NO_TOOLTIP
        eraseButton->setText(QString());
        canvas->setText(QString());
        preview_box->setTitle(QString());
        fps_label->setText(QApplication::translate("MainWindow", "FPS: 12", 0));
        pingPongButton->setText(QApplication::translate("MainWindow", "'Ping Ponged' Order", 0));
        loopButton->setText(QApplication::translate("MainWindow", "Looped Order", 0));
        label->setText(QApplication::translate("MainWindow", "Preview", 0));
        preview_window->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Animation", 0));
        frames_box->setTitle(QString());
        copyFrameButton->setText(QApplication::translate("MainWindow", "Copy", 0));
        deleteFrameButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        onionSkinButton->setText(QApplication::translate("MainWindow", "Onion Skin", 0));
        frames_label->setText(QApplication::translate("MainWindow", "Frames", 0));
        newFrameButton->setText(QApplication::translate("MainWindow", "New", 0));
        newFrameButton->setShortcut(QString());
        color_box->setTitle(QString());
        label_5->setText(QApplication::translate("MainWindow", "Colors", 0));
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
