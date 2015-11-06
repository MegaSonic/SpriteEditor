#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentColor(new QColor()) {
    ui->setupUi(this);

    canvasImage = new QImage();
    canvasImage->size().setHeight(800);
    canvasImage->size().setWidth(600);
    canvasPainter = new QPainter();

}

/*
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
    ui->canvas = paintedFrames[currentFrameIndex];
}
*/

MainWindow::~MainWindow() {
    delete ui;
    delete canvasImage;
    delete canvasPainter;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    statusBar()->showMessage(event->pos().x() + ", " + event->pos().y());
    qDebug() << event->pos();
}

void MainWindow::on_actionDark_triggered()
{
    qDebug("Dark triggered");
    statusBar()->showMessage("Dark theme enabled.");
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::black);
    this->setPalette(pal);
}

void MainWindow::on_actionLight_triggered()
{
    qDebug("Light triggered");
    statusBar()->showMessage("Light theme enabled");
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, Qt::gray);
    this->setPalette(pal);

}
