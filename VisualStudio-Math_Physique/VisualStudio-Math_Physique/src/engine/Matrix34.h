#ifndef __MATRIX34_H__
#define __MATRIX34_H__

#include <array>


class Matrix34
{
public:
    std::array<std::array<double, 4>, 3> values;

    Matrix34();
    Matrix34(std::array<std::array<double, 4>, 3> values);

    Matrix34 operator+(Matrix34);
    Matrix34 operator-(Matrix34);
    Matrix34 operator-();
    Matrix34 operator*(Matrix34);
    Matrix34 operator*(Vector3D);
    Matrix34 operator*(double);
    Matrix34 operator/(double);

    // TODO : Trasnform vector -> V=M*V
    // Vecteur3D operator*(Vecteur3D);

    double determinant();
    Matrix34 inverse();

    // TODO : Transpose
    // Matrix33 transpose();

    // TODO : Faut plutot faire un contructeur
    // void setOrientation(Quaternion);
};
#endif

