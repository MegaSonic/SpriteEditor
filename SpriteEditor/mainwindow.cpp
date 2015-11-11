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
    canvasSize = 256;

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
    QColor color(0,0,0,0);
    currentFrame->fill(color);

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

void MainWindow::on_newFrameButton_clicked()
{
    // Make & keep track of new frame
        currentFrame = new QPixmap(canvasSize, canvasSize);
        QColor color(0,0,0,0);
        currentFrame->fill(color);
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
    if (frames.size() > 1)
    {
        currentFrame = frames[frameCount - 1];

        frames.erase(currentFrameNumber);

        ui->listWidget->takeItem(ui->listWidget->row(selectedItem));

        repaint();
    }
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
