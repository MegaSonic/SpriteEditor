#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QLabel(parent)
{
    mainWindowRef = static_cast<MainWindow *>(parent->parent());
}

void Canvas::myMousePressEvent(QMouseEvent *event)
{
    // Gets the cursor's current position.
    double xPos = event->pos().x();
    double yPos = event->pos().y();

    // Calculates position for grid.
    int xRel = (xPos / this->width()) * 16;
    int yRel = (yPos / this->height()) * 16;

    xRel = xRel * 16;
    yRel = yRel * 16;

    // Draws the points onto the canvas.
    QPainter painter(mainWindowRef->getCurrentFrame());

    painter.setPen(mainWindowRef->getCurrentColor());

    QRect rect = QRect(xRel, yRel, 16, 16);
    painter.drawRect(rect);
    QColor colorFill = mainWindowRef->getCurrentColor();
    colorFill.setAlpha(255);
    painter.fillRect(rect, colorFill);
    mainWindowRef->isCurrentlySaved = false;

    painter.end();
    repaint();
}

void Canvas::myMouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton)
    {
        // Gets the cursor's current position.
        double xPos = event->pos().x();
        double yPos = event->pos().y();

        // Calculates position for grid.
        int xRel = (xPos / this->width()) * mainWindowRef->spriteSize;
        int yRel = (yPos / this->height()) * mainWindowRef->spriteSize;

        xRel = xRel * mainWindowRef->scaleValue;
        yRel = yRel * mainWindowRef->scaleValue;

        // Draws the points onto the canvas.
        QPainter painter(mainWindowRef->getCurrentFrame());

        painter.setPen(mainWindowRef->getCurrentColor());

        QRect rect = QRect(xRel, yRel, 16, 16);
        painter.drawRect(rect);
        painter.fillRect(rect, mainWindowRef->getCurrentColor());
        QColor colorFill = mainWindowRef->getCurrentColor();
        colorFill.setAlpha(255);
        painter.fillRect(rect, colorFill);
        mainWindowRef->isCurrentlySaved = false;

        painter.end();
        repaint();
    }
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(), *mainWindowRef->getCurrentFrame());
}

void Canvas::callRepaint() {
    repaint();
}

QImage Canvas::convertToQImage()
{
    return mainWindowRef->getCurrentFrame()->toImage();
}

