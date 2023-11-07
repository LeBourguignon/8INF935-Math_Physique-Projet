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
    Matrix33(Quaternion quat);

    Matrix33 operator+(Matrix33);
    Matrix33 operator-(Matrix33);
    Matrix33 operator-();
    Matrix33 operator*(Matrix33);
    Matrix33 operator*(double);
    Vecteur3D operator*(Vecteur3D);
    Matrix33 operator/(double);

    double determinant();
    Matrix33 inverse();
    Matrix33 transpose();
    void setOrientation(const Quaternion);
};

#endif