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
        break;
    case Themes::DARK:
    {
        QColor color(15, 35, 136, 255);
        QPalette dark(color);
        mainWindow->setPalette(dark);
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

