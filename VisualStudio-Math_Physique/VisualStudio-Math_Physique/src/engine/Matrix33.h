#ifndef __MATRIX33_H__
#define __MATRIX33_H__

#include <array>

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

    double determinant();
    Matrix33 inverse();
};

#endif