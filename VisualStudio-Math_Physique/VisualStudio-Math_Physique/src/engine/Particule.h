#ifndef __PARTICULE_H__
#define __PARTICULE_H__

#include "Vecteur3D.h"

class Particule
{
public:
	Vecteur3D position, velocite, acceleration;
	double inverseMasse;

	Particule();										// Retourne particule zero. Composition : trois vecteur zero, masse nulle
	Particule(Vecteur3D, Vecteur3D, Vecteur3D, double);
	Particule(Vecteur3D, Vecteur3D, Vecteur3D);			// masse nulle
	Particule(double);									// trois vecteur zéro
	
	//Intégration
	void integration(double deltaTime); // Update position and velocity


	//A implémenter 
	//GetMasse();

};

#endif
