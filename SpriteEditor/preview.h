#ifndef PREVIEW_H
#define PREVIEW_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "mainwindow.h"

class Preview : public QLabel
{
    Q_OBJECT

    QTimer repaintTimer;
    QPainter *painter;
    int frame;
    bool isForwardFps;
    MainWindow * mainWindowRef;
public:
    explicit Preview(QWidget *parent = 0);

signals:
    //void mousePressEvent(QMouseEvent * event);

public slots:
    void mousePressEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * event);
    void paintLoop();
private:

};

#endif // PREVIEW_H
