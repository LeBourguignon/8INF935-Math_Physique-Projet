#ifndef __RESSORT_FIXE_PARTICULE_H__
#define __RESSORT_FIXE_PARTICULE_H__

#include "GenerateurForceParticule.h"
#include "Particule.h"

class RessortFixeParticule : public GenerateurForceParticule
{
private:
	double k;
	double l0;
	Vecteur3D attache;

public:
	RessortFixeParticule(double k, double l0, Vecteur3D attache);
	void actualiserForce(Particule* particule, float duration);
};

#endif