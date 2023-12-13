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
    Matrix33(const Quaternion& quat);

    Matrix33 operator+(const Matrix33&) const;
    Matrix33 operator-(const Matrix33&) const;
    Matrix33 operator-() const;
    Matrix33 operator*(const Matrix33&) const;
    Vecteur3D operator*(const Vecteur3D&) const;
    
    Matrix33 operator*(double) const;
    Matrix33 operator/(double) const;

    double determinant() const;
    Matrix33 inverse() const;
    Matrix33 transpose() const;

    void setOrientation(const Quaternion&);
};

#endif