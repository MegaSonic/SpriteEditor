#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFlags>
#include <QGraphicsScene>
#include <QString>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentColor(new QColor()) {
    ui->setupUi(this);

    canvasImage = new QImage();
    canvasImage->size().setHeight(800);
    canvasImage->size().setWidth(600);
    canvasPainter = new QPainter();


    // Set up the color selector
    colorSelector = new QColorDialog(parent);
    colorSelector->setOption(QColorDialog::ShowAlphaChannel);
    colorSelector->setOption(QColorDialog::NoButtons);
    colorSelector->setOption(QColorDialog::DontUseNativeDialog);
    ui->colorSelectorScroller->setWidget(colorSelector);
    colorSelector->setVisible(true);
    colorSelector->setWhatsThis("Scroll this area to select a color and transparency");

    themes = new Themes();

    // Initialize the first frame
    frameCount = 1;
    currentFrame = new QPixmap(700, 700);

    frames.push_back(currentFrame);
    QString s = "Frame ";
    s.append(QString::number(frameCount));
    ui->listWidget->addItem(s);



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
    delete themes;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        // Gets the cursor's current position.
        xPos = event->pos().x();
        yPos = event->pos().y();

        // Determines if the cursor is in a drawing area.
        if (xPos >= 200 && xPos < 600 && yPos < 320)
        {
            // Calculates position for grid.
            xPos = (xPos / 40) * 40;
            yPos = (yPos / 40) * 40;

            // Adds the point to the list of points to draw.
            QPoint point = QPoint(xPos, yPos);

            pointsList.push_back(point);

            // Draws the points onto the canvas.
            QPainter painter(currentFrame);
            QRect rect = QRect(xPos, yPos, 40, 40);
            painter.drawRect(rect);
            painter.fillRect(rect, Qt::black);
            repaint();
        }
    }
}

void MainWindow::on_actionDark_triggered()
{
    qDebug("Dark triggered");
    statusBar()->showMessage("Dark theme enabled.");
    themes->changeTheme(Themes::DARK);
}

void MainWindow::on_actionLight_triggered()
{
    qDebug("Light triggered");
    statusBar()->showMessage("Light theme enabled");
    themes->changeTheme(Themes::LIGHT);
}

void MainWindow::on_dockWidget_2_visibilityChanged(bool visible)
{

}

void MainWindow::on_actionBlue_triggered()
{
    statusBar()->showMessage("Blue theme enabled");
    themes->changeTheme(Themes::BLUE);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // Gets the cursor's current position.
    xPos = event->pos().x();
    yPos = event->pos().y();

    // Determines if the cursor is in a drawing area.
    if (xPos >= 200 && xPos < 600 && yPos < 320)
    {
    // Calculates position for grid.
    xPos = (xPos / 40) * 40;
    yPos = (yPos / 40) * 40;

    // Adds the point to the list of points to draw.
    QPoint point = QPoint(xPos, yPos);
    pointsList.push_back(point);

    // Draws the points onto the canvas.
    QPainter painter(currentFrame);
    QRect rect = QRect(xPos, yPos, 40, 40);
    painter.drawRect(rect);
    painter.fillRect(rect, Qt::black);
    repaint();

    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,700,700,*currentFrame);
}


void MainWindow::on_newFrameButton_clicked()
{
    currentFrame = new QPixmap(700, 700);
    frameCount++;
    frames.push_back(currentFrame);
    QString s = "Frame ";
    s.append(QString::number(frameCount));
    ui->listWidget->addItem(s);


}

void MainWindow::on_deleteFrameButton_clicked()
{

}

void MainWindow::on_copyFrameButton_clicked()
{

}

void MainWindow::on_onionSkinButton_clicked()
{

}
