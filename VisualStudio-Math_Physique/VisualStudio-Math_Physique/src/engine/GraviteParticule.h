#ifndef __GRAVITE_PARTICULE_H__
#define __GRAVITE_PARTICULE_H__

#include "GenerateurForceParticule.h"

class GraviteParticule : public GenerateurForceParticule
{
private:
	Vecteur3D m_gravite;
public:
	// F = particule->GetMass()*m_gravite
	void actualiserForce(Particule* particule, float duration);
};

#endif