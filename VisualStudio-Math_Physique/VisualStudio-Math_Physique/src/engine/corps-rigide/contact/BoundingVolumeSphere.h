#ifndef __BOUNDING_VOLUME_SPHERE_H__
#define __BOUNDING_VOLUME_SPHERE_H__

#include "../CorpsRigide.h"
#include "../Cuboide/cuboide.h"

class BoundingVolumeSphere
{
public:
	CorpsRigide* corpsRigide;
	double radius;

	BoundingVolumeSphere(CorpsRigide* corpsRigide);
	BoundingVolumeSphere(CorpsRigide* corpsRigide, double radius);

	bool PossibleCollision(BoundingVolumeSphere other);
};

#endif