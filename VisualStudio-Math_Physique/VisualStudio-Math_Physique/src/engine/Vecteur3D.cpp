#include <iostream>
#include <cmath>

#include "Vecteur3D.h"

template <typename T>
Vecteur3D<T>::Vecteur3D(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

template <typename T>
Vecteur3D<T>::Vecteur3D(T x, T y, T z){
    this->x = x;
    this->y = y;
    this->z = z;
}


template <typename T>
T Vecteur3D<T>::norme(){
    return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
}

template <typename T>
Vecteur3D<T> Vecteur3D<T>::direction(){
    return *this/this->norme();
}

template <typename T>
Vecteur3D<T> Vecteur3D<T>::operator*(T s){
    return Vecteur3D(this->x*s, this->y*s, this->z*s);
}

template <typename T>
Vecteur3D<T> Vecteur3D<T>::operator/(T s){
    return Vecteur3D(this->x/s, this->y/s, this->z/s);
}

template <typename T>
Vecteur3D<T> Vecteur3D<T>::operator-(){
    return Vecteur3D(-this->x, -this->y, -this->z);
}


template <typename T>
Vecteur3D<T> Vecteur3D<T>::operator+(Vecteur3D<T> v){
    return Vecteur3D(this->x+v.x, this->y+v.y, this->z+v.z);
}

template <typename T>
Vecteur3D<T> Vecteur3D<T>::operator-(Vecteur3D<T> v){
    return Vecteur3D(this->x-v.x, this->y-v.y, this->z-v.z);
}

template <typename T>
T Vecteur3D<T>::operator*(Vecteur3D<T> v){
    return this->x*v.x + this->y*v.y + this->z*v.z;
}

template <typename T>
Vecteur3D<T> Vecteur3D<T>::operator%(Vecteur3D<T> v){
    return Vecteur3D(this->x*v.y - this->y*v.x,
                        this->y*v.z - this->z*v.y,
                        this->z*v.x - this->x*v.z);
}

template<>
void Vecteur3D<int>::print(){
    std::cout << "Vecteur3D<int>(" << this->x << "," << this->y << "," << this->z << ")" << std::endl;
}
template<>
void Vecteur3D<double>::print(){
    std::cout << "Vecteur3D<double>(" << this->x << "," << this->y << "," << this->z << ")" << std::endl;
}

// Test console
// ------------
// int main(void){
//     Vecteur3D<int> v1 = Vecteur3D<int>();
//     v1.print();
//     Vecteur3D<double> v_1 = Vecteur3D<double>();
//     v_1.print();
//     Vecteur3D<int> v2 = Vecteur3D(1,2,3);
//     v2.print();
//     std::cout << "v2*v2 = " << v2*v2 << std::endl;
//     std::cout << "||v2|| = " << v2.norme() << std::endl;
//     v2.direction().print();
//     Vecteur3D<int> v3 = v2+v2;
//     v3.print();
//     Vecteur3D<double> v4 = Vecteur3D(1.,2.,3.);
//     std::cout << "v4*v4 = " << v4*v4 << std::endl;
//     std::cout << "||v4|| = " << v4.norme() << std::endl;
//     v4.direction().print();
//     v4.print();
//     Vecteur3D<double> v5 = v4+v4;
//     v5.print();
//     v5 = -v4;
//     v5.print();
//     v5 = v4*2;
//     v5.print();
//     v5 = v4/2;
//     v5.print();
//     v3 = v2/2;
//     v3.print();
//     Vecteur3D<double> v6 = Vecteur3D(4.,5.,6.);
//     Vecteur3D<double> v7 = v4%v6;
//     v7.print();
//     v7 = v6%v4;
//     v7.print();
//     v7 = v6%v6;
//     v7.print();
//     return 0;
// }