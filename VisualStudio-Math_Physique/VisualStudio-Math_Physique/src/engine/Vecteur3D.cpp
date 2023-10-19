#include "Vecteur3D.h"

#include <iostream>
#include <cmath>

Vecteur3D::Vecteur3D()
    : Vecteur3D(0, 0, 0)
{
}

Vecteur3D::Vecteur3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}


double Vecteur3D::norme() 
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vecteur3D Vecteur3D::direction() 
{
    return *this / this->norme();
}


Vecteur3D Vecteur3D::operator*(double s) 
{
    return Vecteur3D(this->x * s, this->y * s, this->z * s);
}

Vecteur3D Vecteur3D::operator/(double s) 
{
    return Vecteur3D(this->x / s, this->y / s, this->z / s);
}

Vecteur3D Vecteur3D::operator-() 
{
    return Vecteur3D(-this->x, -this->y, -this->z);
}


Vecteur3D Vecteur3D::operator+(Vecteur3D v) 
{
    return Vecteur3D(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vecteur3D Vecteur3D::operator-(Vecteur3D v) 
{
    return Vecteur3D(this->x - v.x, this->y - v.y, this->z - v.z);
}

double Vecteur3D::operator*(Vecteur3D v) 
{
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vecteur3D Vecteur3D::operator%(Vecteur3D v) 
{
    return Vecteur3D(this->x * v.y - this->y * v.x,
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z);
}


void Vecteur3D::print() 
{
    std::cout << "Vecteur3D(" << this->x << "," << this->y << "," << this->z << ")" << std::endl;
}