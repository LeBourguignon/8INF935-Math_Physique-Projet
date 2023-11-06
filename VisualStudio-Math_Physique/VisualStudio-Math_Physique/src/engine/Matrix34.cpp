#include "Matrix34.h"

Matrix34::Matrix34()
{
	this->values = std::array<std::array<double, 4>, 3>();
}

Matrix34::Matrix34(std::array<std::array<double, 4>, 3> values)		
{
	this->values = values;
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
                value = this->values[i][k] * other.values[k][j];
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
    }
    inverse[0][3] *= -1;
    inverse[1][3] *= -1;
    inverse[2][3] *= -1;

    return Matrix34(inverse);
}