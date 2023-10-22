#ifndef __FLOTTABILITE_PARTICULE_H__
#define __FLOTTABILITE_PARTICULE_H__

#include "GenerateurForceParticule.h"
#include "../Particule.h"

class FlottabiliteParticule : public GenerateurForceParticule
{
private:
	double profondeurMaxObjet;
	double volumeObjet;
	double niveauLiquide;
	double densiteLiquide;
public:
	FlottabiliteParticule(double profondeurMaxObjet, double volumeObjet, double niveauLiquide, double densiteLiquide);
	void ActualiserForce(Particule* p, float duration);
};

#endif