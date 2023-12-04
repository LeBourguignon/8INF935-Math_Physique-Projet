#ifndef __DONNEE_CONCACT_H__
#define __DONNEE_CONCACT_H__

#include "../CorpsRigide.h"

class DonneeContact
{
public:
	CorpsRigide* corpsRigides[2];
	
	double restitution;
	double penetration;

	Vecteur3D pointContact;
	Vecteur3D normalContact;

	DonneeContact(CorpsRigide* particules[2], float restitution, float penetration, Vecteur3D pointContact, Vecteur3D normalContact);
};

#endif