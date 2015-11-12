#ifndef SPRITEPROPERTIESWINDOW_H
#define SPRITEPROPERTIESWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class SpritePropertiesWindow;

}

class MainWindow;

class SpritePropertiesWindow : public QDialog
{
    Q_OBJECT

    MainWindow * mainWindowRef;

public:
    explicit SpritePropertiesWindow(QWidget *parent = 0);

    void enableCancel();

    ~SpritePropertiesWindow();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::SpritePropertiesWindow *ui;
    bool isAccepted;
    bool cancelEnabled;


};

#endif // SPRITEPROPERTIESWINDOW_H
