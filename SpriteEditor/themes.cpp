#include "themes.h"

Themes::Themes()
{
    paletteList.resize(10);

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
                    "border-style: solid;"
                    "padding: 15px;"
                    "padding-left: 10px;"
                    "padding-right: 10px;"
                    "min-width: 50px;"
                    "max-width: 50px;"
                    "min-height: 13px;"
                    "max-height: 13px;"
                    "}"

                    );
        break;
    }
    case Themes::LIGHT:
    {
        QPalette light(QPalette::Window, Qt::gray);
        mainWindow->setPalette(light);
        break;
    }
    }
}

