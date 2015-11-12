#include "preview.h"

Preview::Preview(QWidget *parent) : QLabel(parent)
{
    painter = new QPainter(this);
    frame = 0;
    connect(&repaintTimer, SIGNAL(timeout()), this, SLOT(paintLoop()));
    repaintTimer.start(1000);
    mainWindowRef = static_cast<MainWindow *>(parent->parent()->parent());
}

void Preview::mousePressEvent(QMouseEvent *event)
{
    repaint();
}

void Preview::paintEvent(QPaintEvent *)
{
    std::map<int, QPixmap*>* frames = mainWindowRef->getFrames();
    QPixmap* map = new QPixmap(this->width(), this->height());
    QPainter p(this);
    QColor color(0,0,0,0);
    map->fill(color);
    int counter = 0;
    //TODO: timing bug where the FPS becomes skewed when deleting a frame.
    for (auto frameIterator = frames->begin(); frameIterator != frames->end(); frameIterator++)
    {
        map = frameIterator->second;
        if(counter == frame) {
            break;
        }
        counter++;
    }
    p.eraseRect(0,0,this->width(), this->height());
    p.drawPixmap(0,0,this->width(),this->height(), *map);

    mainWindowRef->repaintFrames();
}

void Preview::paintLoop(){
    int fps = mainWindowRef->getFrameRate();
    int frameCount = mainWindowRef->getFrameCount();
    if(fps <= 0 || frameCount == 1) {
        frame = 0;
        repaintTimer.setInterval(100);
    } else {
        repaintTimer.setInterval(1000/fps);
        MainWindow::PreviewMode mode = mainWindowRef->getPreviewMode();

        if(mode == MainWindow::PreviewMode::LOOP) {
            isForwardFps = true;
        }
        if(isForwardFps) {
            frame++;
        } else {
            frame--;
        }

        if(frame == frameCount) {
            if(mode == MainWindow::PreviewMode::LOOP) {
                frame = 0;
            } else {
                isForwardFps = false;
                frame -= 2;
            }
        } else if(frame == -1) {
            frame = 1;
            isForwardFps = true;
        }
    }

    repaint();
}
