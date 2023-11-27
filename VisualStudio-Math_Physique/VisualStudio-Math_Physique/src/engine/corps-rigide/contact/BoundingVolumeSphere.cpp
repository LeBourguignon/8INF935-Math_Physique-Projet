#include "BoundingVolumeSphere.h"

BoundingVolumeSphere::BoundingVolumeSphere(CorpsRigide CorpR, double radius)
	: corpR(CorpR) , radius(radius)
{
}

BoundingVolumeSphere::BoundingVolumeSphere(Cuboide cuboide)
	: BoundingVolumeSphere(cuboide, (cuboide.dimension / 2).norme())
{
}

bool BoundingVolumeSphere::PossibleColision(BoundingVolumeSphere *other)
//Si elle la somme des rayon est plus grande que la distance entre les deux corps alors il y a colision.
{
	return ((this->radius + other->radius) > (this->corpR.position - other->corpR.position).norme());
}

