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


double Vecteur3D::norme() const
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vecteur3D Vecteur3D::direction() const
{
    double norme = this->norme();
    if (norme == 0)
        return Vecteur3D();
    return *this / this->norme();
}


Vecteur3D Vecteur3D::operator*(double s) const
{
    return Vecteur3D(this->x * s, this->y * s, this->z * s);
}

Vecteur3D Vecteur3D::operator/(double s) const
{
    return Vecteur3D(this->x / s, this->y / s, this->z / s);
}

Vecteur3D Vecteur3D::operator-() const
{
    return Vecteur3D(-this->x, -this->y, -this->z);
}


Vecteur3D Vecteur3D::operator+(Vecteur3D v) const
{
    return Vecteur3D(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vecteur3D Vecteur3D::operator-(Vecteur3D v) const
{
    return Vecteur3D(this->x - v.x, this->y - v.y, this->z - v.z);
}

double Vecteur3D::operator*(Vecteur3D v) const
{
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vecteur3D Vecteur3D::operator%(Vecteur3D v) const
{
    return Vecteur3D(this->x * v.y - this->y * v.x,
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z);
}


void Vecteur3D::print() const
{
    std::cout << "Vecteur3D(" << this->x << "," << this->y << "," << this->z << ")" << std::endl;
}