#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFlags>
#include <QGraphicsScene>
#include <QString>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentColor(new QColor()),
    properties(new SpritePropertiesWindow(this))
    {
    scaleTarget = 600;
    scaleValue = 16;
    spriteSize = 16;

    ui->setupUi(this);

    canvasSize = spriteSize * scaleValue;

    //properties->show();
    // Set up the color selector
    colorSelector = new QColorDialog(parent);
    colorSelector->setOption(QColorDialog::ShowAlphaChannel);
    colorSelector->setOption(QColorDialog::NoButtons);
    colorSelector->setOption(QColorDialog::DontUseNativeDialog);
    ui->colorSelectorScroller->setWidget(colorSelector);

    colorSelector->setVisible(true);
    colorSelector->setWhatsThis("Scroll this area to select a color and transparency");

    themes = new Themes();
    fileIO = new FileIO();

    hasBeenSavedOnce = false;
    isCurrentlySaved = false;

    // Initialize the first frame
    frameCount = 1;
    currentFrame = new QPixmap(canvasSize, canvasSize);
    QColor color(0,0,0,0);
    currentFrame->fill(color);

    frames[frameCount] = currentFrame;
    //frames.push_back(currentFrame);
    QListWidgetItem* item = new QListWidgetItem(QString::number(frameCount), 0);
    ui->listWidget->addItem(item);
    selectedItem = item;
    QIcon currentIcon(currentFrame->copy(0, 0, canvasSize, canvasSize));
    item->setIcon(currentIcon);
    QFont f;
    f.setPointSize(7);
    item->setFont(f);
    frameRate = 12;
    previewMode = MainWindow::LOOP;

    //Connections
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(on_listWidget_itemClicked(QListWidgetItem *item)));

}

MainWindow::~MainWindow() {
    delete ui;
    delete themes;
    delete fileIO;
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

void MainWindow::on_newFrameButton_pressed()
{
    // Make & keep track of new frame
        currentFrame = new QPixmap(canvasSize, canvasSize);
        QColor color(0,0,0,0);
        currentFrame->fill(color);
        frameCount++;
        currentFrameNumber = frameCount;

        //Add to list
        frames[frameCount] = currentFrame;
        QListWidgetItem* item = new QListWidgetItem(QString::number(frameCount), 0);
        ui->listWidget->addItem(item);
        selectedItem = item;

        // Update gui
        item->setSelected(true);
        QPainter p(currentFrame);

        QIcon currentIcon(currentFrame->copy(0, 0, canvasSize, canvasSize));
        item->setIcon(currentIcon);
        QFont f;
        f.setPointSize(10);
        item->setFont(f);

        repaint();

}

void MainWindow::on_deleteFrameButton_pressed()
{
    if (frames.size() > 1)
    {
        currentFrame = frames[frameCount - 1];

        frames.erase(currentFrameNumber);

        ui->listWidget->takeItem(ui->listWidget->row(selectedItem));

        repaint();
    }
}

void MainWindow::on_copyFrameButton_pressed()
{

    QPixmap* newFrame  = new QPixmap(*currentFrame);
      currentFrame = newFrame;
      frameCount++;
      currentFrameNumber = frameCount;

      //Add to list
      frames[frameCount] = currentFrame;
      QListWidgetItem* item = new QListWidgetItem(QString::number(frameCount), 0);
      ui->listWidget->addItem(item);
      selectedItem = item;

      // Update gui
      item->setSelected(true);
      QPainter p(currentFrame);

      QIcon currentIcon(currentFrame->copy(0, 0, canvasSize, canvasSize));
      item->setIcon(currentIcon);
      QFont f;
      f.setPointSize(10);
      item->setFont(f);



      repaint();

}

void MainWindow::on_onionSkinButton_pressed()
{

}

// Gets the frame number from the listWidget tect.
int MainWindow::getFrameNumber(QString s){
    return s.toInt();
}

void MainWindow::repaintFrames() {
    QIcon currentIcon(currentFrame->copy(0, 0, canvasSize, canvasSize));
    selectedItem->setIcon(currentIcon);
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    //Update Icon
        QIcon currentIcon(currentFrame->copy(0, 0, canvasSize, canvasSize));
        selectedItem->setIcon(currentIcon);

     selectedItem = item;
     currentFrameNumber = getFrameNumber(selectedItem->text());
     currentFrame = frames[currentFrameNumber];
     QPainter p(currentFrame);
     repaint();
}

QPixmap* MainWindow::getCurrentFrame() {
    return currentFrame;
}

int MainWindow::getFrameCount() {
    return frameCount;
}

QColor MainWindow::getCurrentColor() {
    return colorSelector->currentColor();
}

void MainWindow::setCurrentColor(QColor color) {
    colorSelector->setCurrentColor(color);
}

std::map<int, QPixmap*>* MainWindow::getFrames()
{
    return &frames;
}

void MainWindow::on_fpsSlider_valueChanged(int val)
{
    frameRate = val;
    QString message;
    message.append("FPS: ");
    message.append(QString::number(val));
    ui->fps_label->setText(message);
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
        QFont qf;
        qf.setBold(true);
        ui->loopButton->setFont(qf);
        qf.setBold(false);
        ui->pingPongButton->setFont(qf);
    }
}

void MainWindow::on_pingPongButton_toggled(bool checked)
{
    if (checked) {
        previewMode = MainWindow::PINGPONG;
        QFont qf;
        qf.setBold(false);
        ui->loopButton->setFont(qf);
        qf.setBold(true);
        ui->pingPongButton->setFont(qf);
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (!hasBeenSavedOnce) {
        MainWindow::fileName = QFileDialog::getSaveFileName(this, "Save file", "", ".ssp");
        fileName.append(".ssp");
        std::vector<QImage> imagesToSave;


        Canvas* canvas = ui->canvas;
        QImage firstConvertedImage = canvas->convertToQImage();
        imagesToSave.push_back(firstConvertedImage);
        std::map<int, QPixmap*>::iterator it = frames.begin();
        it++;

        for (it; it != frames.end(); it++) {
            QPixmap* image = frames[it->first];
            QImage convertedImage = image->toImage();
            imagesToSave.push_back(convertedImage);
        }

        fileIO->save(imagesToSave, fileName);
        hasBeenSavedOnce = true;
        isCurrentlySaved = true;
        statusBar()->showMessage("File saved!");
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    MainWindow::fileName = QFileDialog::getSaveFileName(this, "Save file", "", "*.ssp");
    fileName.append(".ssp");
    std::vector<QImage> imagesToSave;


    Canvas* canvas = ui->canvas;
    QImage firstConvertedImage = canvas->convertToQImage();
    imagesToSave.push_back(firstConvertedImage);
    std::map<int, QPixmap*>::iterator it = frames.begin();
    it++;

    for (it; it != frames.end(); it++) {
        QPixmap* image = frames[it->first];
        QImage convertedImage = image->toImage();
        imagesToSave.push_back(convertedImage);
    }

    fileIO->save(imagesToSave, fileName);
    hasBeenSavedOnce = true;
    isCurrentlySaved = true;
    statusBar()->showMessage("File saved!");
}

void MainWindow::on_actionOpen_triggered()
{
    // Create a dialog box to let them open an image
    QString path = QFileDialog::getOpenFileName(this, "Open image", "", "*.ssp");

    // If they canceled the dialog, don't do anything
    if (path == nullptr) return;

    // Get the file path and load the file
    //MainWindow::fileName = path;

    /*
    std::vector<QImage*> loadedImages = fileIO->load(fileName);
    qDebug() << loadedImages.size();
    qDebug("Loaded file");
*/
    // Clears the frame list
    // ui->listWidget->clear();

/*
    currentFrameNumber = 1;
    frameCount = 1;
*/
/*
    // Create the frames
    for (std::vector<QImage*>::iterator it = loadedImages.begin(); it != loadedImages.end(); it++) {
        QImage* image = *it;
        QPixmap pixmap = QPixmap::fromImage(*image);

        // Construct the new ListWidgetItem
        frames[frameCount] = &pixmap;

        QListWidgetItem* item = new QListWidgetItem(QString::number(frameCount), 0);

        ui->listWidget->addItem(item);
        frameCount++;

        qDebug("Loop executed");
    }
*/
    //currentFrame->fill();

    qDebug("Past loop");

    //hasBeenSavedOnce = false;
    //isCurrentlySaved = false;
    statusBar()->showMessage("File opened!");
    qDebug("Past show message");

    // Program currently crashes here.

    // QPainter p(currentFrame);
    //ui->canvas->repaint();

    qDebug("Past repaint");
}

void MainWindow::on_actionExit_triggered()
{
    if (MainWindow::isCurrentlySaved) {
        QApplication::quit();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("The image has been changed since your last save.");
        msgBox.setInformativeText("Save your changes before exiting?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Save:
        {
            MainWindow::on_actionSave_triggered();
            break;
        }
        case QMessageBox::Discard:
        {
            QApplication::quit();
            break;
        }
        case QMessageBox::Cancel:
        {
            break;
        }
    }
    }
}

void MainWindow::setProjectName(QString name)
{
    projectName = name;
}

QString MainWindow::getProjectName()
{
    return projectName;
}

void MainWindow::setCanvasSize(int size)
{
    canvasSize = size;
}

int MainWindow::getCanvasSize()
{
    return canvasSize;
}

void MainWindow::on_actionSprite_Properties_triggered()
{
   properties->show();
}

void MainWindow::on_drawButton_pressed() {
    ui->canvas->currentTool = 0;
}

void MainWindow::on_eraseButton_pressed() {
    ui->canvas->currentTool = 1;
}

void MainWindow::on_marqueeButton_pressed() {
    ui->canvas->currentTool = 2;
}

void MainWindow::on_eyedropButton_pressed() {
    ui->canvas->currentTool = 3;
}
