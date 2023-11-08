#ifndef __MATRIX34_H__
#define __MATRIX34_H__

#include <array>
#include <glm/glm.hpp>

#include "Vecteur3D.h"
#include "Quaternion.h"
#include "Matrix33.h"

class Matrix34
{
public:
    std::array<std::array<double, 4>, 3> values;

    Matrix34();
    Matrix34(std::array<std::array<double, 4>, 3> values);
    Matrix34(const Vecteur3D& position, const Quaternion& orientation);

    Matrix34 operator*(const Matrix34& other) const;
    Vecteur3D operator*(const Vecteur3D& vecteur) const;

    Matrix34 inverse();

    void setPositionAndOrientation(const Vecteur3D& position, const Quaternion& orientation);

    Vecteur3D transformPosition(const Vecteur3D& position); // TODO
    Vecteur3D transformOrientation(const Vecteur3D& orientation); // TODO

    glm::mat4 toGlmMat4();
};
#endif

