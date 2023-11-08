#ifndef __CUBOIDE_H__
#define __CUBOIDE_H__

#include "../CorpsRigide.h"

class Cuboide : public CorpsRigide
{
public:
	Vecteur3D size;

	Cuboide(Vecteur3D size = Vecteur3D());
	Cuboide(Vecteur3D position, Quaternion orientation, double masse, Vecteur3D size = Vecteur3D());
	Cuboide(Vecteur3D position, Quaternion orientation, Vecteur3D velocite, Vecteur3D velociteAngulaire, double masse, Vecteur3D size = Vecteur3D());
};

#endif