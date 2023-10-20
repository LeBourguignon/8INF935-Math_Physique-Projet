#ifndef __PARTICULE_CONTACT_H__
#define __PARTICULE_CONTACT_H__

#include "Particule.h"

class ContactParticule
{
private:
	Particule* particules[2];

	float restitution;
	float penetration;

	Vecteur3D contactNormal;

	void resoudreVelocite();
	void resoudreInterpenetration();

public:
	ContactParticule(Particule* particules[2], float restitution, float penetration);

	float getVelociteRelative();
	void resoudre(float duration);
};

#endif