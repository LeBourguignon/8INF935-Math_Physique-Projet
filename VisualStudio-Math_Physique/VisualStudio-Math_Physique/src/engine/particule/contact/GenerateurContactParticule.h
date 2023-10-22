#ifndef __GENERATEUR_CONTACT_PARTICULE_H__
#define __GENERATEUR_CONTACT_PARTICULE_H__

#include "ContactParticules.h"

class GenerateurContactParticule
{
public:
	virtual void ajouterContact(ContactParticules& contacts, unsigned int limit) = 0;
};

#endif