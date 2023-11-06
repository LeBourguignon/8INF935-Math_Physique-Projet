#ifndef __MATRIX34_H__
#define __MATRIX34_H__

#include <array>
#include "Vecteur3D.h"


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
    Vecteur3D operator*(Vecteur3D);
    Matrix34 operator*(double);
    Matrix34 operator/(double);

    // TODO : Trasnform vector -> V=M*V
    // Vecteur3D operator*(Vecteur3D);

    
    Matrix34 inverse();

    void setOrientationAndPosition(Quaternion,Vecteur3D);
    Vecteur3D transformPosition(Vecteur3D);
    Vecteur3D transformDirection(Vecteur3D);
};
#endif

