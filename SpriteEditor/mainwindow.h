#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <vector>
#include <QMouseEvent>
#include <QDebug>
#include <QColorDialog>
#include "themes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mouseMoveEvent(QMouseEvent* event);

private slots:

    void on_actionDark_triggered();

    void on_actionLight_triggered();

    void on_dockWidget_2_visibilityChanged(bool visible);

    void on_actionBlue_triggered();

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);


private:
    Ui::MainWindow *ui;
    QColor *currentColor;

    QImage* canvasImage;
    QPainter* canvasPainter;
    QColorDialog* colorSelector;
    Themes* themes;

    int xPos;
    int yPos;
    std::list<QPoint> pointsList;
    QPixmap *p;

    //size of square canvas
    unsigned int canvasSize;
    unsigned int currentFrameIndex;
    //holds each matrix of vectors holding pixel color data for each frame.
    // std::vector<QColor[][]> * frames;
    //hold painted frames which ui elements can reference.
    std::vector<QPixmap*> paintedFrames;


    void paintSprite(QWidget * canvas, int frameIndex);


};

#endif // MAINWINDOW_H
