#ifndef __GENERATEUR_CONTACT_CORPS_RIGIDE_H__
#define __GENERATEUR_CONTACT_CORPS_RIGIDE_H__

#include "GenerateurContact.h"
#include "../CorpsRigide.h"

class GenerateurContactCorpsRigide : public GenerateurContact
{
public:
	CorpsRigide* corpsRigides[2];

	GenerateurContactCorpsRigide(CorpsRigide* corpsRigides[2]);

	// TODO
	void ajouterContact(Contacts& contacts, unsigned int limit) override;

	bool isCollision();
};

// Algorithme d'intersection de M�ller-Trumbore - Wikipedia
bool RayIntersectsTriangle(Vecteur3D rayOrigin, Vecteur3D rayVector, std::array<Vecteur3D, 3>& inTriangle, Vecteur3D& outIntersectionPoint);

#endif