#ifndef __GENERATEUR_CONTACT_PARTICULE_NAIVE_H__
#define __GENERATEUR_CONTACT_PARTICULE_NAIVE_H__

#include "GenerateurContactParticule.h"
#include <vector>

class GenerateurContactParticuleNaive : public GenerateurContactParticule
{
public:
	float radius;

	std::vector<Particule*> particules;

	unsigned int ajouterContact(ContactParticule* contact, unsigned int limit) const;
};

#endif