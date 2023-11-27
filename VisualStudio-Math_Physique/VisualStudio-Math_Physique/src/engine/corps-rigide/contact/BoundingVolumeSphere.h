#ifndef __BOUNDING_VOLUME_SPHERE_H__
#define __BOUNDING_VOLUME_SPHERE_H__

#include "../CorpsRigide.h"
#include "../Cuboide/cuboide.h"

//je lie à un corp, un rayon de détection
//Je compare 2 corps en prenant la distance entre leurs centre et en le comparant à la somme des 2 rayons de détection.

class BoundingVolumeSphere
{
private:
	CorpsRigide corpR;
	double radius;
public:
	BoundingVolumeSphere(CorpsRigide, double);			// lie un rayon à un corp
	BoundingVolumeSphere(Cuboide);						// lie un rayon à un cuboide
	bool PossibleColision(BoundingVolumeSphere *other);	//Si elle la distance est plus petite que la somme des rayon alors il y a colision.

};
#endif


