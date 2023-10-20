#ifndef __LIEN_PARTICULE_H__
#define __LIEN_PARTICULE_H__

#include "GenerateurContactParticule.h"

class LienParticule : public GenerateurContactParticule
{
public:
	Particule* particules[2];

	float longueurActuelle() const;
	unsigned int ajouterContact(ContactParticule* contact, unsigned int limit) const = 0;
};

#endif