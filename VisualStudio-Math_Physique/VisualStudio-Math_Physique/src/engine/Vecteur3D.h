#ifndef __VECTEUR_3D_H__
#define __VECTEUR_3D_H__

#include <iostream>

class Vecteur3D {
public:
    double x;
    double y;
    double z;

    Vecteur3D(); // Returns vector zero
    Vecteur3D(double, double, double);

    double norme() const;
    Vecteur3D direction() const;

    // Scalar operations
    Vecteur3D operator*(double) const;
    Vecteur3D operator/(double) const;
    Vecteur3D operator-() const; // Get opposite vector

    // Vector operations
    Vecteur3D operator+(const Vecteur3D&) const;
    Vecteur3D operator-(const Vecteur3D&) const;
    double operator*(const Vecteur3D&) const; // Scalar product
    Vecteur3D operator%(const Vecteur3D&) const; // Vectorial product

    // Other
    void print();
};

#endif