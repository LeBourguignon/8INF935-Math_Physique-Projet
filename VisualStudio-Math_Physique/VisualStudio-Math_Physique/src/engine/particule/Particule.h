#ifndef __PARTICULE_H__
#define __PARTICULE_H__

#include "../Vecteur3D.h"

class Particule
{
public:
	Vecteur3D position, velocite, acceleration, force;
	double inverseMasse;

	Particule();
	Particule(Vecteur3D position, Vecteur3D velocite, Vecteur3D acceleration);
	Particule(double masse);
	Particule(Vecteur3D position, Vecteur3D velocite, Vecteur3D acceleration, double masse);
	
	void actualiser(double duration);					// Mise à jour de la particule
	double getMass();									// Masse infinie -> Erreur (retourne Constant::masseInfinie = 0)
};

#endif
