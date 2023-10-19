#ifndef __RESSORT_BUNGEE_PARTICULE_H__
#define __RESSORT_BUNGEE_PARTICULE_H__

#include "GenerateurForceParticule.h"
#include "Particule.h"

class RessortBungeeParticule : public GenerateurForceParticule
{
private:
	double k;
	double l0;
	Particule *attache;

public:
	RessortBungeeParticule(double k, double l0, Particule* attache);
	void actualiserForce(Particule* particule, float duration);
};

#endif