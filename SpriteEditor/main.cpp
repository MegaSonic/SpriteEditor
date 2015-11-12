#include "mainwindow.h"
#include "spritepropertieswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Photoshop CC");
    w.show();

    return a.exec();
}
