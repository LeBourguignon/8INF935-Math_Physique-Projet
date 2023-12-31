#ifndef __DONNEE_CONTACT_H__
#define __DONNEE_CONTACT_H__

#include "../CorpsRigide.h"

class DonneeContact
{
public:
	CorpsRigide* corpsRigides[2];
	
	double restitution;
	double penetration;

	Vecteur3D pointContact;
	Vecteur3D normalContact;

	DonneeContact(CorpsRigide* corpsRigides[2], const double& restitution, const double& penetration, const Vecteur3D& pointContact, const Vecteur3D& normalContact);
	DonneeContact(CorpsRigide* corpsRigide0, CorpsRigide* corpsRigide1, const double& restitution, const double& penetration, const Vecteur3D& pointContact, const Vecteur3D& normalContact);
};

#endif