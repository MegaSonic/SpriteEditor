#ifndef QCOLORMATRIX_H
#define QCOLORMATRIX_H

#include <QColor>
#include <vector>

class QColorMatrix
{
private:
    std::vector< std::vector<QColor> > colorMatrix;

public:
    QColorMatrix();

    //TODO add getters/setters
};

#endif // QCOLORMATRIX_H
