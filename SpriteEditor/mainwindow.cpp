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

    //TODO This needs to be moved to an init func
    canvasSize = 32;

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
    currentFrame = new QPixmap(canvasSize, canvasSize);

    frames[frameCount] = currentFrame;
    //frames.push_back(currentFrame);
    QString s = "Frame ";
    s.append(QString::number(frameCount));
    ui->listWidget->addItem(s);

    //Connections
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(on_listWidget_itemClicked(QListWidgetItem *item)));



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
    delete canvasPainter;
    delete themes;
}

//void MainWindow::mouseMoveEvent(QMouseEvent *event) {
//    if (event->buttons() & Qt::LeftButton) {
//        // Gets the cursor's current position.
//        xPos = event->pos().x();
//        yPos = event->pos().y();

//        // Determines if the cursor is in a drawing area.
//        if (xPos >= 200 && xPos < 600 && yPos < 320)
//        {
//            // Calculates position for grid.
//            xPos = (xPos / 40) * 40;
//            yPos = (yPos / 40) * 40;

//            // Adds the point to the list of points to draw.
//            QPoint point = QPoint(xPos, yPos);

//            pointsList.push_back(point);

//            // Draws the points onto the canvas.
//            QPainter painter(currentFrame);
//            QRect rect = QRect(xPos, yPos, 40, 40);
//            painter.drawRect(rect);
//            painter.fillRect(rect, Qt::black);
//            repaint();
//        }
//    }
//}

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

//void MainWindow::mousePressEvent(QMouseEvent *event)
//{
//    // Gets the cursor's current position.
//    xPos = event->pos().x();
//    yPos = event->pos().y();

//    // Determines if the cursor is in a drawing area.
//    if (xPos >= 200 && xPos < 600 && yPos < 320)
//    {
//    // Calculates position for grid.
//    xPos = (xPos / 40) * 40;
//    yPos = (yPos / 40) * 40;

//    // Adds the point to the list of points to draw.
//    QPoint point = QPoint(xPos, yPos);
//    pointsList.push_back(point);

//    // Draws the points onto the canvas.
//    QPainter painter(currentFrame);
//    QRect rect = QRect(xPos, yPos, 40, 40);
//    painter.drawRect(rect);
//    painter.fillRect(rect, Qt::black);
//    repaint();

//    }
//}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,700,700,*currentFrame);
}


void MainWindow::on_newFrameButton_clicked()
{
    // Make & keep track of new frame
        currentFrame = new QPixmap(700, 700);
        frameCount++;
        currentFrameNumber = frameCount;

        //Add to list
        frames[frameCount] = currentFrame;
        QString s = "Frame ";
        s.append(QString::number(frameCount));
        QListWidgetItem* item = new QListWidgetItem(s, 0);
        ui->listWidget->addItem(item);

        // Update gui
        item->setSelected(true);
        QPainter p(currentFrame);
        repaint();
}

void MainWindow::on_deleteFrameButton_clicked()
{
    //  Erase from frames internal list
    frames.erase(currentFrameNumber);

    // Erase from list view
    ui->listWidget->takeItem(ui->listWidget->row(selectedItem));


}

void MainWindow::on_copyFrameButton_clicked()
{
    QPixmap* newFrame  = new QPixmap(*currentFrame);
      currentFrame = newFrame;
      frameCount++;
      currentFrameNumber = frameCount;

      //Add to list
      frames[frameCount] = currentFrame;
      QString s = "Frame ";
      s.append(QString::number(frameCount));
      QListWidgetItem* item = new QListWidgetItem(s, 0);
      ui->listWidget->addItem(item);

      // Update gui
      item->setSelected(true);
      QPainter p(currentFrame);
      repaint();

}

void MainWindow::on_onionSkinButton_clicked()
{

}

// Gets the frame number from the listWidget tect.
int MainWindow::getFrameNumber(QString s){
    s.remove(0, 6);
    return s.toInt();
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
     selectedItem = item;
     currentFrameNumber = getFrameNumber(selectedItem->text());
     qDebug() << selectedItem->text()<< endl;
     currentFrame = frames[currentFrameNumber];
     QPainter p(currentFrame);
     repaint();
}

QPixmap* MainWindow::getCurrentFrame() {
    return currentFrame;
}

QColor MainWindow::getCurrentColor() {
    return colorSelector->currentColor();
}

void MainWindow::on_fpsCounter_valueChanged(int arg1)
{
    frameRate = arg1;
    QString message;
    message.append("Preview framerate changed to ");
    message.append(QString::number(arg1));
    message.append(".");
    statusBar()->showMessage(message);
}

MainWindow::PreviewMode MainWindow::getPreviewMode() {
    return previewMode;
}

int MainWindow::getFrameRate() {
    return frameRate;
}


void MainWindow::on_loopButton_toggled(bool checked)
{
    if (checked) {
        previewMode = MainWindow::LOOP;
        statusBar()->showMessage("Set to looping preview.");
    }
}

void MainWindow::on_pingPongButton_toggled(bool checked)
{
    if (checked) {
        previewMode = MainWindow::PINGPONG;
        statusBar()->showMessage("Set to pingpong preview.");
    }
}
