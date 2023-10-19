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

    double norme();
    Vecteur3D direction();

    // Scalar operations
    Vecteur3D operator*(double);
    Vecteur3D operator/(double);
    Vecteur3D operator-(); // Get opposite vector

    // Vector operations
    Vecteur3D operator+(Vecteur3D);
    Vecteur3D operator-(Vecteur3D);
    double operator*(Vecteur3D); // Scalar product
    Vecteur3D operator%(Vecteur3D); // Vectorial product

    // Other
    void print();
};

#endif