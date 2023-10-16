#ifndef __RESSORT_BUNGEE_FIXE_PARTICULE_H__
#define __RESSORT_BUNGEE_FIXE_PARTICULE_H__

#include "GenerateurForceParticule.h"
#include "Particule.h"

class RessortBungeeFixeParticule : public GenerateurForceParticule
{
private:
	double k;
	double l0;
	Vecteur3D attache;
public:
	RessortBungeeFixeParticule(double k, double l0, Vecteur3D attache);
	void ActualiserForce(Particule* p, float duration);
};

#endif