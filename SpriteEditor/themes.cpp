#include "themes.h"

Themes::Themes()
{
    paletteList.resize(10);

    // This finds the MainWindow widget for later.
    foreach (QWidget* widget, QApplication::topLevelWidgets()) {
      if(widget->inherits("QMainWindow"))
        mainWindow = widget;
    }

    paletteList[Themes::DEFAULT]=mainWindow->palette();

}

void Themes::changeTheme(int themeColor) {

    switch (themeColor) {
    case Themes::DEFAULT:
        mainWindow->setPalette(paletteList[Themes::DEFAULT]);
        mainWindow->setStyleSheet("");
        break;
    case Themes::DARK:
    {
        mainWindow->setStyleSheet(
                    "* {"
                    "background-color: rgb(48, 48, 48);"
                    "color: white;"
                    "}"

                    "QMenu {"
                    "background-color: rgb(48, 48, 48);"
                    "color: white;"
                    "border-color: rgb(48, 48, 48);"
                    "background: rgb(48, 48, 48);"
                    "}"

                    "QMenu::item:selected {"
                    "background-color: rgb(100, 100, 100);"
                    "}"

                    "QMenuBar {"
                    "background-color: transparent;"
                    "}"

                    "QMenuBar::item {"
                    "color : white;"
                    "margin-top:4px;"
                    "spacing: 3px;"
                    "padding: 1px 10px;"
                    "background: transparent;"
                    "border-radius: 4px;"
                    "}"

                    "QPushButton {"
                    "color: white;"
                    "background-color: qlineargradient(spread:pad, x1:0.478, y1:1, x2:0.494, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                    "border-width: 1px;"
                    "border-color: #339;"
                    "padding: 15px;"
                    "padding-left: 10px;"
                    "padding-right: 10px;"
                    "min-width: 50px;"
                    "max-width: 100px;"
                    "min-height: 13px;"
                    "max-height: 26px;"
                    "}"

                    "QPushButton:pressed {"
                    "background-color: qlineargradient(spread:pad, x1:0.478, y1:1, x2:0.494, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(100, 100, 100, 255));"
                    "border-style: inset;"
                    "}"
                    );
        break;
    }
    case Themes::LIGHT:
    {
        mainWindow->setStyleSheet(
                    "* {"
                    "background-color: rgb(222, 222, 222);"
                    "color: black;"
                    "}"

                    "QMenu {"
                    "background-color: rgb(222, 222, 222);"
                    "color: black;"
                    "border-color: rgb(222, 222, 222);"
                    "background: rgb(222, 222, 222);"
                    "}"

                    "QMenu::item:selected {"
                    "background-color: rgb(200, 200, 200);"
                    "}"


                    "QMenuBar {"
                    "background-color: transparent;"
                    "}"

                    "QMenuBar::item {"
                    "color : black;"
                    "margin-top:4px;"
                    "spacing: 3px;"
                    "padding: 1px 10px;"
                    "background: transparent;"
                    "border-radius: 4px;"
                    "}"

                    "QPushButton {"
                    "color: black;"
                    "background-color: qlineargradient(spread:pad, x1:0.478, y1:1, x2:0.494, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(185, 185, 185, 255));"
                    "border-width: 1px;"
                    "border-color: rgb(0, 0, 0);"
                    "padding: 15px;"
                    "padding-left: 10px;"
                    "padding-right: 10px;"
                    "min-width: 50px;"
                    "max-width: 100px;"
                    "min-height: 13px;"
                    "max-height: 26px;"
                    "}"

                    "QPushButton:pressed {"
                    "background-color: qlineargradient(spread:pad, x1:0.478, y1:1, x2:0.494, y2:0, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(100, 100, 100, 255));"
                    "border-style: inset;"
                    "}"

                    );
        break;
    }
    case Themes::BLUE:
    {
        mainWindow->setStyleSheet(
                    "* {"
                    "background-color: rgb(190, 190, 255);"
                    "color: black;"
                    "}"

                    "QMenu {"
                    "background-color: rgb(190, 190, 255);"
                    "color: black;"
                    "border-color: rgb(222, 222, 222);"
                    "background: rgb(222, 222, 222);"
                    "}"

                    "QMenu::item:selected {"
                    "background-color: rgb(150, 150, 255);"
                    "}"


                    "QMenuBar {"
                    "background-color: transparent;"
                    "}"

                    "QMenuBar::item {"
                    "color : black;"
                    "margin-top:4px;"
                    "spacing: 3px;"
                    "padding: 1px 10px;"
                    "background: transparent;"
                    "border-radius: 4px;"
                    "}"

                    "QPushButton {"
                    "color: white;"
                    "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);"
                    "border-width: 1px;"
                    "border-color: #339;"
                    "border-style: solid;"
                    "padding: 15px;"
                    "padding-left: 10px;"
                    "padding-right: 10px;"
                    "min-width: 50px;"
                    "max-width: 100px;"
                    "min-height: 13px;"
                    "max-height: 26px;"
                    "}"

                    "QPushButton:pressed {"
                    "background-color: qlineargradient(spread:pad, x1:0.478, y1:1, x2:0.494, y2:0, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(100, 100, 100, 255));"
                    "border-style: inset;"
                    "}"

                    );
        break;
    }
    }
}

