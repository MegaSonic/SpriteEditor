#ifndef FILEIO_H
#define FILEIO_H

#include <QImage>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QColor>
#include <QRgb>


class FileIO
{

public:
    FileIO();

    void save(std::vector<QImage> images, QString filePath);
    std::vector<QImage> load(QString filePath);

};

#endif // FILEIO_H
