#ifndef __GENERATEUR_CONTACT_LIEN_CORPS_RIGIDE_H__
#define __GENERATEUR_CONTACT_LIEN_CORPS_RIGIDE_H__

#include "GenerateurContact.h"
#include "../CorpsRigide.h"

class GenerateurContactLienCorpsRigides : public GenerateurContact
{
public:
	CorpsRigide* corpsRigides[2];
	Vecteur3D localAttache[2];

	GenerateurContactLienCorpsRigides(CorpsRigide* corpsRigides[2], Vecteur3D localAttache[2]);
};

#endif