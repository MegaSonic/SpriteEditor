#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QLabel(parent)
{

    mainWindowRef = static_cast<MainWindow *>(parent->parent());
}

void Canvas::myMousePressEvent(QMouseEvent *event) {
    qDebug() << "called";
    if (event->buttons() & Qt::LeftButton) {
        // Gets the cursor's current position.
        double xPos = event->pos().x();
        double yPos = event->pos().y();

        // Calculates position for grid.
        xPos = (xPos / this->width()) * 32;
        yPos = (yPos / this->height()) * 32;

        // Draws the points onto the canvas.
        QPainter painter(mainWindowRef->getCurrentFrame());

        //TODO make current color a variable modified by colorSelector slots
        painter.setPen(mainWindowRef->getCurrentColor());
        painter.drawPoint(xPos, yPos);
        painter.end();
        this->setPixmap(*(mainWindowRef->getCurrentFrame()));
    }
}

