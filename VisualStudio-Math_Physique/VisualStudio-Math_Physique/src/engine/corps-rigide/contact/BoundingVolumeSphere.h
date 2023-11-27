#ifndef __BOUNDING_VOLUME_SPHERE_H__
#define __BOUNDING_VOLUME_SPHERE_H__

#include "../CorpsRigide.h"
#include "../Cuboide/cuboide.h"

//je lie � un corp, un rayon de d�tection
//Je compare 2 corps en prenant la distance entre leurs centre et en le comparant � la somme des 2 rayons de d�tection.

class BoundingVolumeSphere
{
private:
	CorpsRigide corpR;
	double radius;
public:
	BoundingVolumeSphere(CorpsRigide, double);			// lie un rayon � un corp
	BoundingVolumeSphere(Cuboide);						// lie un rayon � un cuboide
	bool PossibleColision(BoundingVolumeSphere *other);	//Si elle la distance est plus petite que la somme des rayon alors il y a colision.

};
#endif


