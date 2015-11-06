#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentColor(new QColor()) {
    ui->setupUi(this);
}


void MainWindow::paintEvent(QPaintEvent *) {
    //set painter to pixmap of current frame
    QPainter * painter = new QPainter(paintedFrames[currentFrameIndex]);

    QColor[][] * currentFrameMap = frames->at(currentFrameIndex);
    //draw every pixel in the pixel
    for(int i = 0; i < canvasSize; i++) {
        for(int j = 0; j < canvasSize; j++) {
            painter->setPen(currentFrameMap[i][j]);
            painter->drawPoint(i, j);
        }
    }
    delete painter;
    ui->canvas->addPixMap(paintedFrame[currentFrameIndex]);
    ui->canvas = paintedFrames[currentFrameIndex];
}

MainWindow::~MainWindow() {
    delete ui;
}
