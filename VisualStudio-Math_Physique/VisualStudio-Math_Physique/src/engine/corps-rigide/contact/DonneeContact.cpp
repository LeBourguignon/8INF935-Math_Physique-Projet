#include "DonneeContact.h"

DonneeContact::DonneeContact(CorpsRigide* particules[2], const double& restitution, const double& penetration, const Vecteur3D& pointContact, const Vecteur3D& normalContact)
	: restitution(restitution), penetration(penetration), pointContact(pointContact), normalContact(normalContact)
{
	this->corpsRigides[0] = corpsRigides[0];
	this->corpsRigides[1] = corpsRigides[1];
}
