#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QLabel(parent)
{

    mainWindowRef = static_cast<MainWindow *>(parent->parent());
}

void Canvas::myMousePressEvent(QMouseEvent *event) {

    if (event->buttons() & Qt::LeftButton) {
        // Gets the cursor's current position.
        double xPos = event->pos().x();
        double yPos = event->pos().y();

        // Calculates position for grid.
        int xRel = (xPos / this->width()) * 32;
        int yRel = (yPos / this->height()) * 32;

        xRel = xRel * 32;
        yRel = yRel * 32;

        // Draws the points onto the canvas.
        QPainter painter(mainWindowRef->getCurrentFrame());

        //TODO make current color a variable modified by colorSelector slots
        painter.setPen(mainWindowRef->getCurrentColor());

        qDebug() << "Pos: " << xPos << " " << yPos;
        qDebug() << "Rel: " << xRel << " " << yRel;

        QRect rect = QRect(xRel, yRel, 32, 32);
        painter.drawRect(rect);
        painter.fillRect(rect, mainWindowRef->getCurrentColor());

        painter.end();

        repaint();
        //this->setPixmap(*(mainWindowRef->getCurrentFrame()));
    }
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(), *mainWindowRef->getCurrentFrame());
}

