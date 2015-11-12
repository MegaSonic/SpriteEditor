#ifndef PREVIEW_H
#define PREVIEW_H

#include <QWidget>
#include <QLabel>
#include "mainwindow.h"

class Preview : public QLabel
{
    Q_OBJECT

    MainWindow * mainWindowRef;
public:
    explicit Preview(QWidget *parent = 0);

signals:
    //void mousePressEvent(QMouseEvent * event);

public slots:
    void mousePressEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * event);
};

#endif // PREVIEW_H
