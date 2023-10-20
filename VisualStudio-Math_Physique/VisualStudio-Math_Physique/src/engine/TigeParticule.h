#ifndef __TIGE_PARTICULE_H__
#define __TIGE_PARTICULE_H__

#include "LienParticule.h"

class TigeParticule : public LienParticule
{
public:
	float longueur;

	unsigned int ajouterContact(ContactParticule* contact, unsigned int limit) const;
};

#endif