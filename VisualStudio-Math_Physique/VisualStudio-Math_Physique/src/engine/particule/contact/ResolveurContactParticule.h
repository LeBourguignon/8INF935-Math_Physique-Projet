#ifndef __RESOLVEUR_CONTACT_PARTICULE_H__
#define __RESOLVEUR_CONTACT_PARTICULE_H__

#include "ContactParticules.h"

class ResolveurContactParticule
{
protected:
	unsigned int iteration = 0;

public:
	void resoudreContact(ContactParticules& contacts, float duration);
};

#endif