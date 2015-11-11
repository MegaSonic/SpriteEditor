#ifndef CANVAS_H
#define CANVAS_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include "mainwindow.h"


class Canvas : public QLabel
{
    Q_OBJECT

    MainWindow * mainWindowRef;

public:
    explicit Canvas(QWidget *parent = 0);

signals:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);

public slots:
    void myMousePressEvent(QMouseEvent * event);
    void myMouseMoveEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);

};

#endif // CANVAS_H
