#ifndef __CABLE_PARTICULE_H__
#define __CABLE_PARTICULE_H__

#include "LienParticule.h"

class CableParticule : public LienParticule
{
public:
	float longueurMax;
	float restitution;

	void ajouterContact(ContactParticules& contacts, unsigned int limit);
};

#endif