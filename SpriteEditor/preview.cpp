#include "preview.h"

Preview::Preview(QWidget *parent) : QLabel(parent)
{
    mainWindowRef = static_cast<MainWindow *>(parent->parent());
}

void Preview::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Hello from the preview";




    repaint();
}

void Preview::paintEvent(QPaintEvent *)
{

    std::map<int, QPixmap*>* frames = mainWindowRef->getFrames();
    QPainter painter(this);

    QPixmap* map = new QPixmap(this->width(), this->height());
    QColor color(0,0,0,0);
    map->fill(color);

    QPixmap* clear = new QPixmap(this->width(), this->height());
    clear->fill(color);
    //std::map<int, QPixmap*>::iterator frameIterator;

    for (auto frameIterator = frames->begin(); frameIterator != frames->end(); frameIterator++)
    {
        map = frameIterator->second;
        painter.drawPixmap(0,0,this->width(),this->height(), *map);
        this->setFocus();
        //painter.drawPixmap(0,0,this->width(),this->height(), *clear);
    }

}
