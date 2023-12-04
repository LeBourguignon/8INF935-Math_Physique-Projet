#include "DonneeContact.h"

DonneeContact::DonneeContact(CorpsRigide* corpsRigides[2], float restitution, float penetration, Vecteur3D pointContact, Vecteur3D normalContact)
	: restitution(restitution), penetration(penetration), pointContact(pointContact), normalContact(normalContact)
{
	this->corpsRigides[0] = corpsRigides[0];
	this->corpsRigides[1] = corpsRigides[1];
}
