#ifndef __GRAVITE_PARTICULE_H__
#define __GRAVITE_PARTICULE_H__

#include "GenerateurForceParticule.h"

class GraviteParticule : public GenerateurForceParticule
{
private:
	Vecteur3D gravite;

public:
	GraviteParticule(Vecteur3D gravite);

	void actualiserForce(Particule* particule, float duration);
};

#endif