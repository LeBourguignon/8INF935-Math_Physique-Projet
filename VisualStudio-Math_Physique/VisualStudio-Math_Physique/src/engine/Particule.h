#ifndef __PARTICULE_H__
#define __PARTICULE_H__

#include "Vecteur3D.h"

class Particule
{
public:
	Vecteur3D position, velocite, acceleration, force;
	double inverseMasse;

	Particule(Vecteur3D, Vecteur3D, Vecteur3D, double);

	Particule();										// Retourne particule zero. Composition : trois vecteur zero, masse infinie
	Particule(Vecteur3D, Vecteur3D, Vecteur3D);			// Masse infinie
	Particule(double);									// Trois vecteur zéro
	
	void actualiser(double duration);					// Mise à jour de la particule
	double getMass();									// Masse infinie -> Erreur (retourne Constant::masseInfinie = 10^9)
};

#endif
