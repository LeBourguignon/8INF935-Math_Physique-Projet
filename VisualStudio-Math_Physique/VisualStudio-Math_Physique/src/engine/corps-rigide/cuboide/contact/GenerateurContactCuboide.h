#ifndef __GENERATEUR_CONTACT_CUBOIDE_H__
#define __GENERATEUR_CONTACT_CUBOIDE_H__

#include "../../contact/GenerateurContact.h"
#include "../Cuboide.h"

class GenerateurContactCuboide : public GenerateurContact
{
public:
	Cuboide* cuboides[2];

	GenerateurContactCuboide(Cuboide* cuboides[2]);

	void ajouterContact(Contacts& contacts, unsigned int limit) override;
};

#endif