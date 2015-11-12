#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <vector>
#include <QMouseEvent>
#include <QDebug>
#include <QColorDialog>
#include <QPushButton>
#include <QListWidgetItem>
#include <QString>
#include <map>
#include "themes.h"
#include "fileio.h"
#include "spritepropertieswindow.h"
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class SpritePropertiesWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int spriteSize;
    int scaleValue;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void mouseMoveEvent(QMouseEvent* event);

    QPixmap* getCurrentFrame();
    QColor getCurrentColor();
    void setCurrentColor(QColor color);
    void setProjectName(QString name);
    QString getProjectName();
    void setCanvasSize(int size);
    int getCanvasSize();
    std::map<int, QPixmap*>* getFrames();

    enum PreviewMode { LOOP = 0, PINGPONG = 1 };

    bool hasBeenSavedOnce;
    bool isCurrentlySaved;

    PreviewMode getPreviewMode();
    int getFrameRate();
    int getFrameCount();
    void repaintFrames();


private slots:

    void on_actionDark_triggered();

    void on_actionLight_triggered();

    void on_dockWidget_2_visibilityChanged(bool visible);

    void on_actionBlue_triggered();

    void on_newFrameButton_pressed();

    void on_deleteFrameButton_pressed();

    void on_copyFrameButton_pressed();

    void on_onionSkinButton_pressed();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_fpsSlider_valueChanged(int val);

    void on_loopButton_toggled(bool checked);

    void on_pingPongButton_toggled(bool checked);

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionSprite_Properties_triggered();

    void on_drawButton_pressed();

    void on_eraseButton_pressed();

    void on_marqueeButton_pressed();

    void on_eyedropButton_pressed();

private:
    Ui::MainWindow *ui;
    QColor *currentColor;

    QImage* canvasImage;
    QColorDialog* colorSelector;
    Themes* themes;
    FileIO* fileIO;
    SpritePropertiesWindow* properties;

    QString projectName;


    //size of square canvas
    int canvasSize;
    int scaleTarget;

    std::map<int, QPixmap*> frames;
    int frameCount;
    int currentFrameNumber;
    QListWidgetItem* selectedItem;

    int xPos;
    int yPos;
    std::list<QPoint> pointsList;
    QPixmap *currentFrame;

    int frameRate;
    PreviewMode previewMode;

    QString fileName;


    unsigned int currentFrameIndex;
    //holds each matrix of vectors holding pixel color data for each frame.
    // std::vector<QColor[][]> * frames;
    //hold painted frames which ui elements can reference.
    std::vector<QPixmap*> paintedFrames;


    void paintSprite(QWidget * canvas, int frameIndex);
    int getFrameNumber(QString s);


};

#endif // MAINWINDOW_H
