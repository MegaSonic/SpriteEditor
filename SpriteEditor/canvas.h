#ifndef CANVAS_H
#define CANVAS_H

#include <QLabel>
#include <QPixmap>

class Canvas : public QLabel
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);

signals:
    void mousePressEvent(QMouseEvent * mEvent);

public slots:

};

#endif // CANVAS_H
