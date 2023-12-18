#include "GenerateurContactLienCorpsRigides.h"

GenerateurContactLienCorpsRigides::GenerateurContactLienCorpsRigides(CorpsRigide* corpsRigides[2], Vecteur3D localAttache[2])
{
	this->corpsRigides[0] = corpsRigides[0];
	this->corpsRigides[1] = corpsRigides[1];

	this->localAttache[0] = localAttache[0];
	this->localAttache[1] = localAttache[1];
}