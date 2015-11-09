#ifndef THEMES_H
#define THEMES_H

#include <QPalette>
#include <vector>
#include <QWidget>
#include <QApplication>
#include <QColor>

class Themes
{
public:
    Themes();

    std::vector<QPalette> paletteList;

    enum ThemeColor { DEFAULT = 0, DARK = 1, LIGHT = 2, BLUE = 3 };

    void changeTheme(int themeColor);

private:
    QWidget* mainWindow;
};

#endif // THEMES_H
