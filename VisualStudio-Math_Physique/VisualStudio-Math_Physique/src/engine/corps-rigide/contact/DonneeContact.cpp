#include "DonneeContact.h"

DonneeContact::DonneeContact(CorpsRigide* corpsRigides[2], const double& restitution, const double& penetration, const Vecteur3D& pointContact, const Vecteur3D& normalContact)
	: DonneeContact(corpsRigides[0], corpsRigides[1], restitution, penetration, pointContact, normalContact)
{
}

DonneeContact::DonneeContact(CorpsRigide* corpsRigide0, CorpsRigide* corpsRigide1, const double& restitution, const double& penetration, const Vecteur3D& pointContact, const Vecteur3D& normalContact)
	: restitution(restitution), penetration(penetration), pointContact(pointContact), normalContact(normalContact)
{
	this->corpsRigides[0] = corpsRigide0;
	this->corpsRigides[1] = corpsRigide1;
}
