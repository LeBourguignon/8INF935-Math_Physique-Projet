#ifndef __GENERATEURS_CONTACT_PARTICULE_H__
#define __GENERATEURS_CONTACT_PARTICULE_H__

#include "GenerateurContactParticule.h"

class GenerateursContactParticule : public std::vector<GenerateurContactParticule*>
{
public:
	void ajouterContact(ContactParticules& contacts, unsigned int limit);
};

#endif