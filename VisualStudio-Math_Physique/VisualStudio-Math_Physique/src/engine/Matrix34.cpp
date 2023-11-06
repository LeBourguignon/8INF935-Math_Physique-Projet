#include "Matrix34.h"
#include "Matrix33.h"
#include "Vecteur3D.h"
#include <iostream>

#define ligne 3
#define colonne 4

Matrix34::Matrix34()
{
	this->values = std::array<std::array<double, colonne>, ligne>();			//instancie une matrice vide en donnant à la matrice un array vide de taille adapté 
}

Matrix34::Matrix34(std::array<std::array<double, colonne>, ligne> values)		
{
	this->values = values;
}

Matrix34 Matrix34::operator+(Matrix34 other)
{
    std::array<std::array<double, colonne>, ligne> ret = std::array<std::array<double, colonne>, ligne>();
    for (int i = 0; i < ligne; i += 1) 
    {
        for (int j = 0; j < colonne; j += 1) 
        {
            ret[i][j] = this->values[i][j] + other.values[i][j];
        }
    }
    return Matrix34(ret);
}

Matrix34 Matrix34::operator-(Matrix34 other)
{
    std::array<std::array<double, colonne>, ligne> ret = std::array<std::array<double, colonne>, ligne>();
    for (int i = 0; i < ligne; i += 1) 
    {
        for (int j = 0; j < colonne; j += 1) 
        {
            ret[i][j] = this->values[i][j] - other.values[i][j];
        }
    }
    return Matrix34(ret);
}

Matrix34 Matrix34::operator-()
{
    std::array<std::array<double, colonne>, ligne> ret = std::array<std::array<double, colonne>, ligne>();
    for (int i = 0; i < ligne; i += 1) 
    {
        for (int j = 0; j < colonne; j += 1) 
        {
            ret[i][j] = -this->values[i][j];
        }
    }
    return Matrix34(ret);
}

Matrix34 Matrix34::operator*(Matrix34 other)
{/*
    std::array<std::array<double, colonne>, ligne> ret = std::array<std::array<double, colonne>, ligne>();
    for (int i = 0; i < ligne; i += 1) {
        for (int j = 0; j < colonne; j += 1) {
            ret[i][j] = this->values[i][0] * other.values[0][j] + this->values[i][1] * other.values[1][j] + this->values[i][2] * other.values[2][j];
        }
    }
    return Matrix34(ret);
 */
}

Matrix34 Matrix34::operator*(double x)
{
    std::array<std::array<double, colonne>, ligne> ret = std::array<std::array<double, colonne>, ligne>();
    for (int i = 0; i < ligne; i += 1) 
    {
        for (int j = 0; j < colonne; j += 1) 
        {
            ret[i][j] = this->values[i][j] * x;
        }
    }
    return Matrix34(ret);
}

Matrix34 Matrix34::operator/(double x)
{
    if (x == 0) {
        std::cout << "Attention : Masse infini" << std::endl;
    }
    else 
    {
        std::array<std::array<double, colonne>, ligne> ret = std::array<std::array<double, colonne>, ligne>();
        for (int i = 0; i < ligne; i += 1)
        {
            for (int j = 0; j < colonne; j += 1)
            {
                ret[i][j] = this->values[i][j] / x;
            }
        }
        return Matrix34(ret);
    }
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

    Vecteur3D Vec = Vecteur3D(-this->values[0][3], -this->values[1][3], -this->values[2][3]);
    
    std::array<std::array<double, colonne>, ligne> inverse = std::array<std::array<double, colonne>, ligne>();
    for (int i = 0; i < 3; i += 1)
    {
        for (int j = 0; j < 3; j += 1)
        {
            inverse[i][j] = Mat.values[i][j];
        }
    }
    inverse[0][3] = Vec.x;
    inverse[1][3] = Vec.y;
    inverse[2][3] = Vec.z;

    return Matrix34(inverse);
}




