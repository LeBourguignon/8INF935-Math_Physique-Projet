#ifndef __MATRIX33_H__
#define __MATRIX33_H__

#include <array>
#include "Vecteur3D.h"
#include "Quaternion.h"

class Matrix33{
public:
    std::array<std::array<double, 3>, 3> values;

    Matrix33();
    Matrix33(std::array<std::array<double, 3>, 3> values);

    Matrix33 operator+(Matrix33);
    Matrix33 operator-(Matrix33);
    Matrix33 operator-();
    Matrix33 operator*(Matrix33);
    Matrix33 operator*(double);
    Matrix33 operator/(double);

    // TODO : Trasnform vector -> V=M*V
    // Vecteur3D operator*(Vecteur3D);

    double determinant();
    Matrix33 inverse();

    // TODO : Transpose
    // Matrix33 transpose();

    // TODO :
    // void setOrientation(Quaternion);
};

#endif