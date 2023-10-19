#ifndef __RESSORT_PARTICULE_H__
#define __RESSORT_PARTICULE_H__

#include "GenerateurForceParticule.h"
#include "Particule.h"

class RessortParticule : public GenerateurForceParticule
{
private:
	double k;
	double l0;
	Particule *attache;

public:
	RessortParticule(double k, double l0, Particule *attache);
	void actualiserForce(Particule* particule, float duration);
};

#endif