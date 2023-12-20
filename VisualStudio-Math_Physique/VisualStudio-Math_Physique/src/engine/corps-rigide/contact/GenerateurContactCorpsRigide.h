#ifndef __GENERATEUR_CONTACT_CORPS_RIGIDE_H__
#define __GENERATEUR_CONTACT_CORPS_RIGIDE_H__

#include "GenerateurContact.h"
#include "../CorpsRigide.h"

class GenerateurContactCorpsRigide : public GenerateurContact
{
public:
	CorpsRigide* corpsRigides[2];
	double restitution;

	GenerateurContactCorpsRigide(CorpsRigide* corpsRigides[2], const double& restitution);
	GenerateurContactCorpsRigide(CorpsRigide* corpsRigide0, CorpsRigide* corpsRigide1, const double& restitution);

	void ajouterContact(Contacts& contacts, unsigned int limit) override;

	bool isCollision(const std::vector<Vecteur3D>& sommetsCorpsRigide0, const std::vector<Vecteur3D>& sommetsCorpsRigide1, std::vector<Vecteur3D>& outIntersectionPoints);
};

// Algorithme d'intersection de Möller-Trumbore - Wikipedia
bool RayIntersectsTriangle(Vecteur3D rayOrigin, Vecteur3D rayVector, std::array<Vecteur3D, 3>& inTriangle, Vecteur3D& outIntersectionPoint);

#endif