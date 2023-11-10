#include "Matrix34.h"
#include <iostream>

Matrix34::Matrix34()
    : Matrix34(std::array<std::array<double, 4>, 3>())
{
}

Matrix34::Matrix34(std::array<std::array<double, 4>, 3> values)	
    : values(values)
{
}

Matrix34::Matrix34(const Vecteur3D& position, const Quaternion& orientation)
    : Matrix34()
{
    Matrix33 m(orientation);
    for (int i = 0; i < m.values.size(); ++i)
    {
        for (int j = 0; j < m.values[i].size(); ++j)
        {
            this->values[i][j] = m.values[i][j];
        }
    }

    this->values[0][3] = position.x;
    this->values[1][3] = position.y;
    this->values[2][3] = position.z;
}


Matrix34 Matrix34::operator*(const Matrix34& other) const
{
    Matrix34 resultat;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            double value = 0;

            for (int k = 0; k < 3; ++k)
            {
                value += this->values[i][k] * other.values[k][j];
            }

            if (j == 3)
                value += this->values[i][3];

            resultat.values[i][j] = value;
        }
    }
    return resultat;
}

Vecteur3D Matrix34::operator*(const Vecteur3D& vecteur) const
{
    return Vecteur3D(
        this->values[0][0] * vecteur.x + this->values[0][1] * vecteur.y + this->values[0][2] + vecteur.z + this->values[0][3],
        this->values[1][0] * vecteur.x + this->values[1][1] * vecteur.y + this->values[1][2] + vecteur.z + this->values[1][3],
        this->values[2][0] * vecteur.x + this->values[2][1] * vecteur.y + this->values[2][2] + vecteur.z + this->values[2][3]
    );
}


Matrix34 Matrix34::inverse()
{
    Matrix33 Mat = Matrix33();
    for (int i = 0; i < 3; i += 1) {
        for (int j = 0; j < 3; j += 1) {
            Mat.values[i][j] = this->values[i][j];
        }
    }
    Mat = Mat.inverse();
    
    std::array<std::array<double, 4>, 3> inverse = std::array<std::array<double, 4>, 3>();
    for (int i = 0; i < 3; i += 1)
    {
        for (int j = 0; j < 3; j += 1)
        {
            inverse[i][j] = Mat.values[i][j];
        }
        inverse[i][3] *= -1;
    }

    return Matrix34(inverse);
}


void Matrix34::setPositionAndOrientation(const Vecteur3D& position, const Quaternion& orientation)
{
    Matrix34 other(position, orientation);
    Matrix34 new_mat = other * *this * other.inverse();
    this->values = new_mat.values;
}


glm::mat4 Matrix34::toGlmMat4()
{
    return glm::mat4({
        this->values[0][0], this->values[1][0], this->values[2][0], 0,
        this->values[0][1], this->values[1][1], this->values[2][1], 0,
        this->values[0][2], this->values[1][2], this->values[2][2], 0,
        this->values[0][3], this->values[1][3], this->values[2][3], 1,
    });
}
