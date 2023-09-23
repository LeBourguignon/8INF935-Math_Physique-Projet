#include <iostream>
#include <cmath>

#include "Vecteur3D.h"

Vecteur3D::Vecteur3D() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vecteur3D::Vecteur3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}


double Vecteur3D::norme() {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vecteur3D Vecteur3D::direction() {
    return *this / this->norme();
}

Vecteur3D Vecteur3D::operator*(double s) {
    return Vecteur3D(this->x * s, this->y * s, this->z * s);
}

Vecteur3D Vecteur3D::operator/(double s) {
    return Vecteur3D(this->x / s, this->y / s, this->z / s);
}

Vecteur3D Vecteur3D::operator-() {
    return Vecteur3D(-this->x, -this->y, -this->z);
}


Vecteur3D Vecteur3D::operator+(Vecteur3D v) {
    return Vecteur3D(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vecteur3D Vecteur3D::operator-(Vecteur3D v) {
    return Vecteur3D(this->x - v.x, this->y - v.y, this->z - v.z);
}

double Vecteur3D::operator*(Vecteur3D v) {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vecteur3D Vecteur3D::operator%(Vecteur3D v) {
    return Vecteur3D(this->x * v.y - this->y * v.x,
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z);
}

void Vecteur3D::print() {
    std::cout << "Vecteur3D(" << this->x << "," << this->y << "," << this->z << ")" << std::endl;
}

// Test console
// ------------
//int main(void) {
//    Vecteur3D v_1 = Vecteur3D();
//    v_1.print();
//    Vecteur3D v4 = Vecteur3D(1., 2., 3.);
//    std::cout << "v4*v4 = " << v4 * v4 << std::endl;
//    std::cout << "||v4|| = " << v4.norme() << std::endl;
//    v4.direction().print();
//    v4.print();
//    Vecteur3D v5 = v4 + v4;
//    v5.print();
//    v5 = -v4;
//    v5.print();
//    v5 = v4 * 2;
//    v5.print();
//    v5 = v4 / 2;
//    v5.print();
//    Vecteur3D v6 = Vecteur3D(4., 5., 6.);
//    Vecteur3D v7 = v4 % v6;
//    v7.print();
//    v7 = v6 % v4;
//    v7.print();
//    v7 = v6 % v6;
//    v7.print();
//    return 0;
//}