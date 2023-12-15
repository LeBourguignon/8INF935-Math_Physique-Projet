#ifndef __GENERATEURS_CONTACT_H__
#define __GENERATEURS_CONTACT_H__

#include "GenerateurContact.h"

class GenerateursContact : public std::vector<GenerateurContact*>
{
public:
	void ajouterContact(Contacts& contacts, unsigned int limit);

	void deleteGenerateurs();
};

#endif