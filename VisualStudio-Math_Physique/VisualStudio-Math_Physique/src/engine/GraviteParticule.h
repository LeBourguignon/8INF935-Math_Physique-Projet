#ifndef __GRAVITEPARTICULE_H__
#define __GRAVITEPARTICULE_H__

#include "GenerateurForceParticule.h"

class GraviteParticule : public GenerateurForceParticule
{
private:
	Vecteur3D m_gravite;
public:
	// F = particule->GetMass()*m_gravite
	void ActualiserForce(Particule* p, float duration);


};

#endif