#ifndef __LIEN_PARTICULE_H__
#define __LIEN_PARTICULE_H__

#include "GenerateurContactParticule.h"

class LienParticule : public GenerateurContactParticule
{
public:
	Particule* particules[2];

	float longueurActuelle() const;

	void ajouterContact(ContactParticules& contacts, unsigned int limit) = 0;
};

#endif