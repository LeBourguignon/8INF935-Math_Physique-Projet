#ifndef __TIGE_PARTICULE_H__
#define __TIGE_PARTICULE_H__

#include "LienParticule.h"

class TigeParticule : public LienParticule
{
public:
	float longueur;

	void ajouterContact(ContactParticules& contacts, unsigned int limit);
};

#endif