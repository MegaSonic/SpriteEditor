#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <vector>
#include <QMouseEvent>
#include <QDebug>
#include <QColorDialog>
#include <QPushButton>
#include <QListWidgetItem>
#include <map>
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
//    void mouseMoveEvent(QMouseEvent* event);

    QPixmap* getCurrentFrame();

    QColor getCurrentColor();

private slots:

    void on_actionDark_triggered();

    void on_actionLight_triggered();

    void on_dockWidget_2_visibilityChanged(bool visible);

    void on_actionBlue_triggered();

    void paintEvent(QPaintEvent *event);

    //void mousePressEvent(QMouseEvent *event);

    void on_newFrameButton_clicked();

    void on_deleteFrameButton_clicked();

    void on_copyFrameButton_clicked();

    void on_onionSkinButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);


private:
    Ui::MainWindow *ui;
    QColor *currentColor;

    QImage* canvasImage;
    QPainter* canvasPainter;
    QColorDialog* colorSelector;
    Themes* themes;

    std::map<int, QPixmap*> frames;
    int frameCount;
    int currentFrameNumber;
    QListWidgetItem* selectedItem;

    int xPos;
    int yPos;
    std::list<QPoint> pointsList;
    QPixmap *currentFrame;

    //size of square canvas
    unsigned int canvasSize;
    unsigned int currentFrameIndex;
    //holds each matrix of vectors holding pixel color data for each frame.
    // std::vector<QColor[][]> * frames;
    //hold painted frames which ui elements can reference.
    std::vector<QPixmap*> paintedFrames;


    void paintSprite(QWidget * canvas, int frameIndex);
    int getFrameNumber(QString s);


};

#endif // MAINWINDOW_H
