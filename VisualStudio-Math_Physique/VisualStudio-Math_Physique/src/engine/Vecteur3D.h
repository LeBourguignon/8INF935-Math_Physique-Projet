#ifndef __VECTEUR3D_H__
#define __VECTEUR3D_H__

#include <iostream>

class Vecteur3D {
public:
    double x;
    double y;
    double z;
    Vecteur3D(); // returns vector zero
    Vecteur3D(double, double, double);

    double norme();
    Vecteur3D direction();

    // Scalar operations
    Vecteur3D operator*(double);
    Vecteur3D operator/(double);
    Vecteur3D operator-(); // get opposite vector

    // Vector operations
    Vecteur3D operator+(Vecteur3D);
    Vecteur3D operator-(Vecteur3D);
    double operator*(Vecteur3D); // scalar product
    Vecteur3D operator%(Vecteur3D); // vectorial product

    // Other
    void print();
};

#endif