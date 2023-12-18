#include "BoundingVolumeSphere.h"

BoundingVolumeSphere::BoundingVolumeSphere(CorpsRigide* corpsRigide)
	: BoundingVolumeSphere(corpsRigide, corpsRigide->forme.maxRayon)
{
}

BoundingVolumeSphere::BoundingVolumeSphere(CorpsRigide* corpsRigide, double radius)
	: corpsRigide(corpsRigide), radius(radius)
{
}

bool BoundingVolumeSphere::PossibleCollision(BoundingVolumeSphere other)
{
	return ((this->radius + other.radius) > (this->corpsRigide->position - other.corpsRigide->position).norme());
}

