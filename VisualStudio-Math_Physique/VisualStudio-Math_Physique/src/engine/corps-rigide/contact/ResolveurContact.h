#ifndef __RESOLVEUR_CONCACT_H__
#define __RESOLVEUR_CONCACT_H__

#include "Contact.h"

class ResolveurContact
{
protected:
	unsigned int iteration = 0;

public:
	void resoudreContact(Contact& contact, float duration);
};

#endif