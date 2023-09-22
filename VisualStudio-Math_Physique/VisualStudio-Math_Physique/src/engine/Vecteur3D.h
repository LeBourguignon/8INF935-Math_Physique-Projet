#ifndef __VECTEUR3D_H__
#define __VECTEUR3D_H__

#include <iostream>

template <typename T>
class Vecteur3D{
    public:
        T x;
        T y;
        T z;
    Vecteur3D(); // returns vector zero
    Vecteur3D(T, T, T);

    T norme();
    Vecteur3D<T> direction();

    // Scalar operations
    Vecteur3D<T> operator*(T);
    Vecteur3D<T> operator/(T);
    Vecteur3D<T> operator-(); // get opposite vector

    // Vector operations
    Vecteur3D<T> operator+(Vecteur3D<T>);
    Vecteur3D<T> operator-(Vecteur3D<T>);
    T operator*(Vecteur3D<T>); // scalar product
    Vecteur3D<T> operator%(Vecteur3D<T>); // vectorial product

    // Other
    void print();
};

#endif