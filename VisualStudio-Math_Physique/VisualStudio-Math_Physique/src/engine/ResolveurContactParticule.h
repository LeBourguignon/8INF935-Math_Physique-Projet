#ifndef __RESOLVEUR_CONTACT_PARTICULE_H__
#define __RESOLVEUR_CONTACT_PARTICULE_H__

#include "ContactParticule.h"

class ResolveurContactParticule
{
protected:
	unsigned int iteration;

public:
	void resoudreContact(ContactParticule* contactArray, unsigned int numContact, float duration);
};

#endif