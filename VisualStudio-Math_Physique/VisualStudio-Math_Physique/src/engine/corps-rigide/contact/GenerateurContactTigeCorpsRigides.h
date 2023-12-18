#ifndef __GENERATEUR_CONTACT_TIGE_CORPS_RIGIDE_H__
#define __GENERATEUR_CONTACT_TIGE_CORPS_RIGIDE_H__

#include "GenerateurContactLienCorpsRigides.h"
#include "../CorpsRigide.h"

class GenerateurContactTigeCorpsRigides : public GenerateurContactLienCorpsRigides
{
public:
	double longueur;

	GenerateurContactTigeCorpsRigides(CorpsRigide* corpsRigides[2], Vecteur3D localAttache[2], double longueur);

	void ajouterContact(Contacts& contacts, unsigned int limit) override;
};

#endif