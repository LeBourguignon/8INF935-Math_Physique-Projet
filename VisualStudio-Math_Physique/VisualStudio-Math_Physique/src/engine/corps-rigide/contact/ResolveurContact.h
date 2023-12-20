#ifndef __RESOLVEUR_CONTACT_H__
#define __RESOLVEUR_CONTACT_H__

#include "Contacts.h"

class ResolveurContact
{
private:
	unsigned int iteration = 0;
	int nbIterationMax = 0;

	void resoudreContactsInterpenetration(Contacts& contacts, float duration);
	void resoudreContactsVelocite(Contacts& contacts, float duration);

public:
	void resoudreContacts(Contacts& contacts, float duration);
};

#endif