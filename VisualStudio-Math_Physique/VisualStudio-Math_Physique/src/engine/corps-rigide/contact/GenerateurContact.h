#ifndef __GENERATEUR_CONTACT_H__
#define __GENERATEUR_CONTACT_H__

#include "Contacts.h"

class GenerateurContact
{
public:
	virtual void ajouterContact(Contacts& contacts, unsigned int limit) = 0;
};

#endif