#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    QColor *currentColor;

    //size of square canvas
    unsigned int canvasSize;
    unsigned int currentFrameIndex;
    //holds each matrix of vectors holding pixel color data for each frame.
    std::vector<QColor[][]> * frames;
    //hold painted frames which ui elements can reference.
    std::vector<QPixmap*> paintedFrames;


    void paintSprite(QWidget * canvas, int frameIndex);


};

#endif // MAINWINDOW_H
