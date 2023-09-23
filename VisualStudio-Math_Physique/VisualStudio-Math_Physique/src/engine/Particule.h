#ifndef __PARTICULE_H__
#define __PARTICULE_H__

#include "Vecteur3D.h"

class Particule
{
public:
	Vecteur3D position, velocite, acceleration;

	Particule();// returns particule zero, made of three vector zero
	Particule(Vecteur3D, Vecteur3D, Vecteur3D);

	//Intégration
	void integration(double deltaTime); // Update position and velocity

};

#endif
