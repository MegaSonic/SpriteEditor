#include "fileio.h"

FileIO::FileIO()
{

}

///
/// \brief FileIO::save Saves a series of QImages to a file
/// \param images       Each image in the sprite animation
/// \param filePath     The filepath to be saved to
///
void FileIO::save(std::vector<QImage> images, QString filePath) {
    QImage firstImage = images.at(0);
    // This converts the image to use RGBA 32-bit format, probably not needed
    firstImage = firstImage.convertToFormat(QImage::Format_RGBA8888);

    // Get the bits from the image
    // uchar* bits = image.bits();

    // Create or open a file at file path
    QFile file(filePath);

    if (file.open(QIODevice::ReadWrite)) {
        // Create our text stream
        QTextStream stream(&file);

        // First, write the height, width, and number of frames in the image

        stream << firstImage.height() << " " << firstImage.width() << "\n";
        stream << images.size() << "\n";

        // Iterate over every image
        for (std::vector<QImage>::iterator it = images.begin(); it != images.end(); it++) {
            QImage image = *it;

            // Iterates over every pixel in the image
            for (int h = 0; h < image.height(); h++) {
                for (int w = 0; w < image.width(); w++) {

                    // Get the pixel, and save it in the file
                    QColor pixel = image.pixel(w, h);
                    stream << pixel.red() << " " << pixel.green() << " " << pixel.blue() << " " << pixel.alpha();
                }
                stream << "\n";
            }
        }

        file.close();
    }
}

///
/// \brief FileIO::load   Loads an image file from the file path provided
/// \param filePath       The file path to load
/// \return               A vector of QImage with their pixel data created
///
std::vector<QImage> FileIO::load(QString filePath) {
    std::vector<QImage> returnImages;

    QFile file(filePath);

    int width;
    int height;
    int frames;

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        QString line;

        // Get the height of the image
        stream >> line;
        height = line.toInt();

        // Get the width of the image
        line = "";
        stream >> line;
        width = line.toInt();

        // Get the number of images
        line = "";
        stream >> line;
        frames = line.toInt();

        // Now get the pixel information
        line = "";
        stream >> line;

        // Loop over every image frame
        for (int i = 0; i < frames; i++) {

            // First, construct the image
            QImage image(width, height, QImage::Format_RGBA8888);

            // Loop over every pixel in the image
            for (int h = 0; h < height; h++) {
                for (int w = 0; w < width; w++) {
                    // Get the RGBA value from the four 'words'

                    line = "";
                    stream >> line;
                    int red = line.toInt();

                    line = "";
                    stream >> line;
                    int green = line.toInt();

                    line = "";
                    stream >> line;
                    int blue = line.toInt();

                    line = "";
                    stream >> line;
                    int alpha = line.toInt();

                    QColor color(red, green, blue, alpha);

                    image.setPixel(w, h, color.rgba());
                }

            }
            // Add the image to the vector
            returnImages.push_back(image);
        }
        file.close();
    }

    return returnImages;
}

