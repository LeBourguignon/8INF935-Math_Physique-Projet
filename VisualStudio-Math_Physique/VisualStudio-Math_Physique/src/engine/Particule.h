#ifndef __PARTICULE_H__
#define __PARTICULE_H__

#include "Vecteur3D.h"

class Particule
{
public:
	Vecteur3D position, velocite, acceleration;
	double inverseMasse;

	Particule(Vecteur3D, Vecteur3D, Vecteur3D, double);
	Particule();										// Retourne particule zero. Composition : trois vecteur zero, masse nulle
	Particule(Vecteur3D, Vecteur3D, Vecteur3D);			// Masse nulle
	Particule(double);									// Trois vecteur zéro
	
	// Intégration
	void actualiser(double duration);					// Update position and velocity particule à temps de vie
	double getMass();									// utilise par gravite
};

#endif
