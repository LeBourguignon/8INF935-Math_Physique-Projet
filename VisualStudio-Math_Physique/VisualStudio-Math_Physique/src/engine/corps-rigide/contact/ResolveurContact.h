#ifndef __RESOLVEUR_CONTACT_H__
#define __RESOLVEUR_CONTACT_H__

#include "Contacts.h"

class ResolveurContact
{
protected:
	unsigned int iteration = 0;

public:
	void resoudreContacts(Contacts& contacts, float duration);
};

#endif