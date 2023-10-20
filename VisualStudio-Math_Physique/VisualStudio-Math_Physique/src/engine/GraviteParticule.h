#ifndef __GRAVITE_PARTICULE_H__
#define __GRAVITE_PARTICULE_H__

#include "GenerateurForceParticule.h"

class GraviteParticule : public GenerateurForceParticule
{
private:
	Vecteur3D m_gravite = { 0, -8.9, 0 };
public:
	void actualiserForce(Particule* particule, float duration);
};

#endif