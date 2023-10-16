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
	bool fixe;
public:
	RessortParticule(double k, double l0, Particule *attache);
	RessortParticule(double k, double l0, Vecteur3D attache);
	~RessortParticule();
	void ActualiserForce(Particule* p, float duration);
};

#endif