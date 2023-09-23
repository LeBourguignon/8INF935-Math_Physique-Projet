#include "Particule.h"
#include <iostream>

Particule::Particule()  
// returns particule zero, made of three vector zero
{
    this->position      = Vecteur3D();       
    this->velocite      = Vecteur3D();
    this->acceleration  = Vecteur3D();
}

Particule::Particule(Vecteur3D position, Vecteur3D velocite , Vecteur3D acceleration)
{
    this->position      = position;
    this->velocite      = velocite;
    this->acceleration  = acceleration;
}

void Particule::integration(double deltaTime)
{
    //mise à jour position
    this->position = this->position + this->velocite * deltaTime + this->acceleration * 0.5 * deltaTime * deltaTime;
    //mise à jour vitesse
    this->velocite = this->velocite * 0.9999 + this->acceleration * deltaTime;

}


//Test particule ------
//int main1(void) {
//	Particule P0 = Particule(Vecteur3D(3, 5, 1), Vecteur3D(3, 3, 1), Vecteur3D(1, 0, 0));
//	Particule P1 = Particule(Vecteur3D(2, 1, 1), Vecteur3D(1, 2, 1), Vecteur3D());
//
//	P0.integration(2);
//	P1.integration(3);
//
//
//	std::cout << "P0 position :";
//	P1.position.print();
//	std::cout << "P0 velocite :";
//	P1.velocite.print();
//	std::cout << "P0 acceleration :";
//	P1.acceleration.print();
//
//	return 0;
//}
