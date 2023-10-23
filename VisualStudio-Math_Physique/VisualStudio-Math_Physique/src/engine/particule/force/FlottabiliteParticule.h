#ifndef __FLOTTABILITE_PARTICULE_H__
#define __FLOTTABILITE_PARTICULE_H__

#include "GenerateurForceParticule.h"
#include "../Particule.h"

class FlottabiliteParticule : public GenerateurForceParticule
{
private:
	double hauteurObjet;
	double volumeObjet;
	double niveauLiquide;
	double densiteLiquide;

public:
	FlottabiliteParticule(double hauteurObjet, double volumeObjet, double niveauLiquide, double densiteLiquide);
	void actualiserForce(Particule* particule, float duration);
};

#endif