#ifndef __GENERATEUR_CONTACT_PARTICULE_H__
#define __GENERATEUR_CONTACT_PARTICULE_H__

#include "ContactParticule.h"

class GenerateurContactParticule
{
public:
	virtual unsigned int ajouterContact(ContactParticule* contact, unsigned int limit) const = 0;
};

#endif